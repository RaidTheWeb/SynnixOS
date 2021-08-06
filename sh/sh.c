#include "parse.h"
#include "readline.h"
#include "token.h"
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <list.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ttyctl.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <synnixos.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <string.h>

/** @file
 * @brief Shell entry point
 * 
 */

/**
 * @brief Do the buffer?
 * 
 */
bool do_buffer = true;

/**
 * @brief Enable token debugging
 * 
 */
bool token_debug = false;

/**
 * @brief Enable Abstract Syntax Tree debugging
 * 
 */
bool ast_debug = false;

/**
 * @brief Enable interactive mode
 * 
 */
bool interactive = true;

/**
 * @brief Shell script input file
 * 
 */
FILE *input_file;

/**
 * @brief Evaluate nodes
 * 
 * @return int 
 */
int eval(struct node *);

/**
 * @brief Username buffer
 * 
 */
char username[1024];

/**
 * @brief Hostname buffer
 * 
 */
char hostname[256];

/**
 * @brief Get username and copy to buffer
 * 
 */
void getuser() {
    strcpy(username, getenv("USER"));
}

/**
 * @brief Get hostname (nodename) and copy to buffer
 * 
 */
void gethost() {
    struct utsname hostbuf;
    uname(&hostbuf);

    int len = strlen(hostbuf.nodename);
    memcpy(hostname, hostbuf.nodename, len+1);
}

#define LINE_LEN 4096

#define FALLBACK_PS1 "[\\u@\\h] \\w$ "

void print_prompt(char* format, char* buffer) {
    char cwdbuffer[256];
    getcwd(cwdbuffer, 256);

    size_t offset = 0;

    while (*format) {
        if(*format == '\\') {
            format++;
            switch (*format) {
                case '\\':
                    buffer[offset++] = *format;
                    format++;
                    break;
                case '[':
                    format++;
                    break;
                case ']':
                    format++;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7': {
                    int i = (*format) - '0';
                    format++;
                    if(*format >= '0' && *format <= '7') {
                        i *= 8;
                        i += (*format) - '0';
                        format++;
                        if(*format >= '0' && *format <= '7') {
                            i *= 8;
                            i += (*format) - '0';
                            format++;
                        }
                    }
                    buffer[offset++] = i;
                    break;
                }

                case 'e':
                    buffer[offset++] = '\033';
                    format++;
                    break;

                case 'd':
                    {
                        // TODO: Date buffer format
                    }
                    format++;
                    break;

                case 't':
                    {
                        // TODO: Time buffer format
                    }
                    format++;
                    break;

                case 'h':
                    {
                        int size = sprintf(buffer+offset, "%s", hostname);
                        offset += size;
                    }
                    format++;
                    break;
                
                case 'u':
                    {
                        int size = sprintf(buffer+offset, "%s", username);
                        offset += size;
                    }
                    format++;
                    break;
                
                case 'w':
                    {
                        int size = sprintf(buffer+offset, "%s", cwdbuffer);
                        offset += size;
                    }
                    format++;
                    break;

                case '$':
                    buffer[offset++] = '$';
                    format++;
                    break;
                
                case 'r':
                    {
                        int size = sprintf(buffer+offset, "%s", 0);
                        offset += size;
                    }
                    format++;
                    break;
                default:
                    {
                        int size = sprintf(buffer+offset, "\\%c", *format);
                        offset += size;
                    }
                    format++;
                    break;
            }
        } else {
            buffer[offset++] = *format;
            format++;
        }
    }

    buffer[offset] = '\0';
}

/**
 * @brief Draw user prompt
 * 
 */
void draw_prompt() {
    char buf[1024];
    getuser();
    gethost();
    print_prompt(FALLBACK_PS1, buf);
    fprintf(stdout, "%s", buf);
}

/**
 * @brief Handle a single line
 * 
 * @return int 
 */
int handle_one_line() {
    if (interactive) draw_prompt();
    char buffer[1024] = {0};
    int ret_val = 127;
    list tokens;
    list_init(&tokens);

    if (do_buffer && interactive) {
        ttyctl(STDIN_FILENO, TTY_SETBUFFER, 0);
        ttyctl(STDIN_FILENO, TTY_SETECHO, 0);
        ttyctl(STDIN_FILENO, TTY_SETPGRP, getpid());
        if (read_line_interactive(buffer, 256) == -1) return 2;
    } else {
        if (input_file == stdin) {
            ttyctl(STDIN_FILENO, TTY_SETBUFFER, 1);
            ttyctl(STDIN_FILENO, TTY_SETECHO, 1);
            ttyctl(STDIN_FILENO, TTY_SETPGRP, getpid());
        }
        if (read_line_simple(input_file, buffer, 256) == -1) return 2;
    }

    if (!buffer[0]) return 0;

    if (tokenize(buffer, &tokens)) {
        if (token_debug) {
            list_for_each(struct token, t, &tokens, node) {
                token_fprint(stderr, t);
                printf("\n");
            }
        }
        struct node *node = parse(&tokens);
        if (node) {
            if (ast_debug) node_fprint(stderr, node);
            ret_val = eval(node);
        }
    }


    if (ret_val >= 128 && ret_val < 128 + 32) {
        fprintf(stderr, "terminated by signal %i\n", ret_val - 128);
    } else if (ret_val != 0) {
        fprintf(stderr, "-> %i\n", ret_val);
    }

    return 0;
}

/**
 * @brief Handle signal
 * 
 * @param signal 
 */
void signal_handler(int signal) {
    return;
}

void help(const char *progname) {
    fprintf(stderr,
            "usage: %s [-nd]\n"
            "  -n     disable tty buffering\n"
            "  -d     token debug mode\n"
            "  -a     ast debug mode\n",
            progname);
}

int main(int argc, char **argv) {
    int pid = getpid();
    setpgid(pid, pid);
    input_file = stdin;

    signal(SIGINT, signal_handler);

    int opt;
    while ((opt = getopt(argc, argv, "ndah")) != -1) {
        switch (opt) {
        case 'n': do_buffer = false; break;
        case 'd': token_debug = true; break;
        case 'a': ast_debug = true; break;
        case '?': // FALLTHROUGH :)
        case 'h': help(argv[0]); return 0;
        }
    }

    if (argv[optind]) {
        input_file = fopen(argv[optind], "r");
        if (!input_file) {
            perror("fopen");
            return EXIT_FAILURE;
        }
        do_buffer = false;
        interactive = false;
    }
    if (!isatty(fileno(stdin))) interactive = false;
    if (interactive) printf("SynnixOS Shell\n");

    while (handle_one_line() == 0) {}

    return EXIT_SUCCESS;
}
