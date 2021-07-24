#pragma once
#ifndef SNX_SH_TOKEN_H
#define SNX_SH_TOKEN_H

#include "list.h" // <list.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>

/** @file
 * @brief Lexer header file 
 * 
 */

/**
 * @brief Token types
 * 
 */
enum token_type {
    TOKEN_OR,        // '||'
    TOKEN_AND,       // '&&'
    TOKEN_PIPE,      // '|'
    TOKEN_OPAREN,    // '('
    TOKEN_CPAREN,    // ')'
    TOKEN_APPEND,    // '>>'
    TOKEN_ERRAPPEND, // '2>>'
    TOKEN_ERROUTPUT, // '2>'
    TOKEN_INPUT,     // '<'
    TOKEN_OUTPUT,    // '>'
    TOKEN_AMPERSAND, // '&'
    TOKEN_SEMICOLON, // ';'
    TOKEN_STRING,    // "''" | '""'
    TOKEN_VAR,       // '$""'
};

/**
 * @brief Token struct
 * 
 */
struct token {
    enum token_type type;
    const char *string;
    off_t begin, end;
    list_node node;
};

void token_print(struct token *t);
void token_fprint(FILE *, struct token *t);
bool tokenize(const char *string, list_head *out);
char *token_strdup(struct token *t);
char *token_strcpy(char *dest, struct token *t);

#endif
