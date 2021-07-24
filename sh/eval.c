#include "parse.h"
#include "token.h"
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ttyctl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <synnixos.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

/** @file
 * @brief Evaluate shell commands
 * C source for evaluating shell commands after parsing.
 */

void completely_destroy_array(char* array) {
    memset(array, 0, strlen(array));
}

int eval_pipeline(struct pipeline *pipeline) {
    pid_t last_child = -1;
    assert(!list_empty(&pipeline->commands));
    int next_stdin_fd = 0;
    int next_stdout_fd = 1;
    int is_first = 1;
    list_for_each(struct command, c, &pipeline->commands, node) {
        int pipefds[2];

        if (strcmp(c->argv[0], "exit") == 0) exit(0);

        if (c->node.next != &pipeline->commands) {
            // there's another command after this one
            pipe(pipefds);
            if (next_stdout_fd > 1) close(next_stdout_fd);
            next_stdout_fd = pipefds[1];
        } else {
            if (next_stdout_fd > 1) close(next_stdout_fd);
            next_stdout_fd = 1;
        }

        pid_t pid;
        if ((pid = fork()) == 0) {
            pid = getpid();

            if (pipeline->pgrp) {
                setpgid(0, pipeline->pgrp);
            } else {
                setpgid(0, pid);
            }

            if (next_stdin_fd != STDIN_FILENO) {
                dup2(next_stdin_fd, STDIN_FILENO);
                close(next_stdin_fd);
            }
            if (next_stdout_fd != STDOUT_FILENO) {
                dup2(next_stdout_fd, STDOUT_FILENO);
                close(next_stdout_fd);
            }

            if (c->stdin_file) {
                int fd = open(c->stdin_file, O_RDONLY);
                if (fd < 0) {
                    fprintf(stderr, "Error opening %s", c->stdin_file);
                    perror("");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
            if (c->stdout_file) {
                int fd =
                    open(c->stdout_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                if (fd < 0) {
                    fprintf(stderr, "Error opening %s", c->stdout_file);
                    perror("");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }
            if (c->stderr_file) {
                int fd =
                    open(c->stderr_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
                if (fd < 0) {
                    fprintf(stderr, "Error opening %s", c->stderr_file);
                    perror("");
                    exit(1);
                }
                dup2(fd, STDERR_FILENO);
                close(fd);
            }

            /* 
            /BIN SEARCH PATH
            */
            int fd = open("/bin", O_RDONLY);

            struct snx_dirent dirent_buf[128];
            int entries = readdir(fd, dirent_buf, 128);

            for (int i = 0; i < entries; i++) {
                struct snx_dirent *entry = &dirent_buf[i];
                if(strcmp(entry->name, c->argv[0]) == 0) {
                    char path[128] = { "" };
                    char bin[6];
                    char executable[16];
                    strcpy(bin, "/bin/");
                    strcpy(executable, c->argv[0]);
                    strcat(path, bin);
                    strcat(path, executable);
                    completely_destroy_array(bin);
                    completely_destroy_array(executable);
                    execve(path, c->argv, NULL);
                    perror("execve");
                    exit(126);
                }
            }

            /*
            /USR/BIN SEARCH PATH
            */
            int usrfd = open("/usr/bin", O_RDONLY);

            struct snx_dirent usrdirent_buf[128];
            int usrentries = readdir(usrfd, usrdirent_buf, 128);

            for (int i = 0; i < usrentries; i++) {
                struct snx_dirent *entry = &usrdirent_buf[i];
                if(strcmp(entry->name, c->argv[0]) == 0) {
                    char usrpath[128] = { "" };
                    char usrbin[10];
                    char usrexecutable[16];
                    strcpy(usrbin, "/usr/bin/");
                    strcpy(usrexecutable, c->argv[0]);
                    strcat(usrpath, usrbin);
                    strcat(usrpath, usrexecutable);
                    execve(usrpath, c->argv, NULL);
                    perror("execve");
                    exit(126);
                }
            }


            execve(c->argv[0], c->argv, NULL);
            perror("execve");
            exit(126);
        } else {
            last_child = pid;
            if (pipeline->pgrp == 0) {
                pipeline->pgrp = pid;
                ttyctl(STDIN_FILENO, TTY_SETBUFFER, 1);
                ttyctl(STDIN_FILENO, TTY_SETECHO, 1);
                ttyctl(STDIN_FILENO, TTY_SETPGRP, pid);
            }
        }

        if (next_stdin_fd > 1) close(next_stdin_fd);
        next_stdin_fd = pipefds[0];
    }

    int status;
    int pipeline_status = 0;
    errno = 0;
    while (errno != ECHILD) {
        pid_t pid = waitpid(-pipeline->pgrp, &status, 0);
        if (pid == last_child) pipeline_status = status;
    }
    return pipeline_status;
}

int eval(struct node *node) {
    if (node->type == NODE_PIPELINE) return eval_pipeline(node->pipeline);
    if (node->type == NODE_BINOP) {
        int lhs = eval(node->left);
        if (node->op == NODE_AND && lhs != 0) return lhs;
        if (node->op == NODE_OR && lhs == 0) return lhs;
        return eval(node->right);
    }
    fprintf(stderr, "Error: cannot evaluate node of type %i\n", node->type);
    return -1;
}
