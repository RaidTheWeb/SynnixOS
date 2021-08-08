#ifndef HERMES_TOKEN_H
#define HERMES_TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_STRING_VALUE,
        TOKEN_CHAR_VALUE,
        TOKEN_INTEGER_VALUE,
        TOKEN_FLOAT_VALUE,
        TOKEN_NUMBER_VALUE,
        TOKEN_BOOLEAN_VALUE,
        TOKEN_ID,
        TOKEN_ANON_ID,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_LBRACKET,
        TOKEN_RBRACKET,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_EQUALS,
        TOKEN_EQUALS_EQUALS,
        TOKEN_NOT_EQUALS,
        TOKEN_NOT,
        TOKEN_SEMI,
        TOKEN_COMMA,
        TOKEN_PLUS,
        TOKEN_PLUS_EQUALS,
        TOKEN_MINUS,
        TOKEN_MINUS_EQUALS,
        TOKEN_STAR,
        TOKEN_STAR_EQUALS,
        TOKEN_DIV,
        TOKEN_PERCENTAGE,
        TOKEN_DOT,
        TOKEN_LESS_THAN,
        TOKEN_LARGER_THAN,
        TOKEN_AND,
        TOKEN_QUESTION,
        TOKEN_COLON,
        TOKEN_EOF,
    } type;

    char* value;
} token_T;

token_T* init_token(int type, char* value);

token_T* token_copy(token_T* token);

void token_free(token_T* token);

char* token_to_string(token_T* token);
#endif
