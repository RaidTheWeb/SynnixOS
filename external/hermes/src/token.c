#include "include/token.h"
#include <stdlib.h>
#include <string.h>


token_T* init_token(int type, char* value)
{
    token_T* token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->type = type;
    token->value = calloc(strlen(value) + 1, sizeof(char));
    strcpy(token->value, value);

    return token;
}

token_T* token_copy(token_T* token)
{
    return init_token(token->type, token->value);
}

void token_free(token_T* token)
{
    free(token->value);
    free(token);
}

char* token_to_string(token_T* token)
{
    char* str = calloc(strlen(token->value) + 1, sizeof(char));
    strcpy(str, token->value);

    return str;
}
