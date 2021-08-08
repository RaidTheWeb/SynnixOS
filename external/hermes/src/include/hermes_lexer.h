#ifndef HERMES_LEXER_H
#define HERMES_LEXER_H
#include "token.h"
#include <stdlib.h>


typedef struct HERMES_LEXER_STRUCT
{
    char* contents;
    size_t contents_length;

    char current_char;
    unsigned int char_index;
    unsigned int line_n;
} hermes_lexer_T;

hermes_lexer_T* init_hermes_lexer(char* contents);

void hermes_lexer_free(hermes_lexer_T* hermes_lexer);

token_T* hermes_lexer_get_next_token(hermes_lexer_T* hermes_lexer);

token_T* hermes_lexer_advance_with_token(hermes_lexer_T* hermes_lexer, int type);

void hermes_lexer_advance(hermes_lexer_T* hermes_lexer);

void hermes_lexer_expect_char(hermes_lexer_T* hermes_lexer, char c);

void hermes_lexer_skip_whitespace(hermes_lexer_T* hermes_lexer);

void hermes_lexer_skip_inline_comment(hermes_lexer_T* hermes_lexer);

void hermes_lexer_skip_block_comment(hermes_lexer_T* hermes_lexer);

token_T* hermes_lexer_collect_string(hermes_lexer_T* hermes_lexer);

token_T* hermes_lexer_collect_char(hermes_lexer_T* hermes_lexer);

token_T* hermes_lexer_collect_number(hermes_lexer_T* hermes_lexer);

token_T* hermes_lexer_collect_id(hermes_lexer_T* hermes_lexer);

char* hermes_lexer_current_charstr(hermes_lexer_T* hermes_lexer);
#endif
