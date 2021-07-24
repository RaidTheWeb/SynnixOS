#include "readline.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/** @file
 * @brief Basic Readline C source file
 * 
 */

/**
 * @brief History start
 * 
 */
struct history_item history_base = {0};

/**
 * @brief History end
 * 
 */
struct history_item *history_top = &history_base;

/**
 * @brief Clear a line
 * 
 * @param buf 
 * @param ix 
 */
void clear_line(char *buf, long *ix) {
    while (*ix > 0) {
        *ix -= 1;
        buf[*ix] = '\0';
        printf("\x08 \x08");
    }
}

/**
 * @brief Print Backspace
 * 
 * @param buf 
 * @param ix 
 */
void backspace(char *buf, long *ix) {
    if (*ix == 0) return;
    *ix -= 1;
    buf[*ix] = '\0';
    printf("\x08 \x08");
}

/**
 * @brief Load a line
 * 
 * @param buf 
 * @param ix 
 * @param new_line 
 */
void load_line(char *buf, long *ix, char *new_line) {
    clear_line(buf, ix);
    while (*new_line) {
        buf[*ix] = *new_line;
        printf("%c", *new_line);
        new_line += 1;
        *ix += 1;
    }
}

/**
 * @brief Store a line in history
 * 
 * @param line_to_store 
 * @param len 
 */
void store_history_line(char *line_to_store, long len) {
    struct history_item *node = malloc(sizeof(struct history_item));
    node->history_line = strdup(line_to_store);

    node->previous = history_top;
    node->next = NULL;
    history_top->next = node;
    history_top = node;
}

/**
 * @brief Get a line from history
 * 
 * @param buf 
 * @param ix 
 * @param current 
 */
void load_history_line(char *buf, long *ix, struct history_item *current) {
    clear_line(buf, ix);
    if (!current->history_line) return;
    load_line(buf, ix, current->history_line);
}

/**
 * @brief Interactive readline
 * 
 * @param buf 
 * @param max_len 
 * @return long 
 */
long read_line_interactive(char *buf, size_t max_len) {
    long ix = 0;
    int readlen = 0;
    char cb[256] = {0};

    struct history_item local = {
        .previous = history_top,
    };
    struct history_item *current = &local;

    while (true) {
        memset(cb, 0, 256);
        readlen = read(STDIN_FILENO, cb, 256);
        if (readlen == -1) {
            perror("read()");
            return -1;
        }
        if (readlen == 0) return -1;

        if (cb[0] == '\x1b') {
        esc_seq:
            if (strcmp(cb, "\x1b[A") == 0) { // up arrow
                if (current->previous) current = current->previous;
                load_history_line(buf, &ix, current);
                continue;
            } else if (strcmp(cb, "\x1b[B") == 0) { // down arrow
                if (current->next) current = current->next;
                load_history_line(buf, &ix, current);
                continue;
            } else if (strcmp(cb, "\x1b[D") == 0) { // left arrow
                // TODO: Implement Left Arrow support
                continue;
            } else if (strcmp(cb, "\x1b[C") == 0) { // right arrow
                // TODO: Implement Right Arrow Support
                continue;
            } else {
                if (strlen(cb) > 3) {
                    printf("unknown escape-sequence %s\n", &cb[1]);
                    continue;
                }
                int rl = read(STDIN_FILENO, &cb[readlen], 1);
                if (rl > 0) {
                    readlen += rl;
                } else {
                    perror("read()");
                }
                goto esc_seq;
            }
        }

        for (int i = 0; i < readlen; i++) {
            char escape_status = 0;
            char c = cb[i];

            switch (c) {
            case 0x7f: // backspace
                backspace(buf, &ix);
                continue;
            case 0x0b: // ^K
                clear_line(buf, &ix);
                continue;
            case 0x0e: // ^N
                if (current->previous) current = current->previous;
                load_history_line(buf, &ix, current);
                continue;
            case 0x08: // ^H
                if (current->next) current = current->next;
                load_history_line(buf, &ix, current);
                continue;
            case '\n': goto done;
            }

            if (ix + 1 == max_len) goto done; // continue;

            if (!isprint(c)) {
                printf("^%c", c + '@');
                continue;
            }

            buf[ix++] = c;
            buf[ix] = '\0';
            putchar(c);
            cb[i] = 0;
        }
    }

done:
    if (ix > 0) store_history_line(buf, ix);
    putchar('\n');
    return ix;
}

/**
 * @brief Simple readline
 * 
 * @param file 
 * @param buf 
 * @param limit 
 * @return long 
 */
long read_line_simple(FILE *file, char *buf, size_t limit) {
    if (feof(file)) return -1;

    char *v = fgets(buf, limit, file);
    if (v == NULL) return -1;

    int ix = strlen(buf);

    /**
     * @brief Incredibly destructive hack for buffer
     * 
     */
    if (buf[ix - 1] == '\n') {
        buf[ix - 1] = '\0';
        ix -= 1;
    }
    return 0;
}
