#include "include/hermes_lexer.h"
#include "include/string_utils.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

/**
 * Create a new hermes_lexer
 *
 * @param char* contents
 *
 * @return hermes_lexer_T*
 */
hermes_lexer_T* init_hermes_lexer(char* contents)
{
    hermes_lexer_T* hermes_lexer = calloc(1, sizeof(struct HERMES_LEXER_STRUCT));

    hermes_lexer->contents = contents;
    hermes_lexer->contents_length = strlen(contents);

    hermes_lexer->char_index = 0;
    hermes_lexer->line_n = 1;
    hermes_lexer->current_char = hermes_lexer->contents[hermes_lexer->char_index];

    return hermes_lexer;
}

/**
 * Deallocate a hermes_lexer
 *
 * @param hermes_lexer_T* hermes_lexer
 */
void hermes_lexer_free(hermes_lexer_T* hermes_lexer)
{
    free(hermes_lexer->contents);
    free(hermes_lexer);
}

/**
 * Get the next token from the lexer
 *
 * @param hermes_lexer_T* hermes_lexer
 *
 * @return token_T*
 */
token_T* hermes_lexer_get_next_token(hermes_lexer_T* hermes_lexer)
{
    while (hermes_lexer->current_char != '\0' && hermes_lexer->char_index < hermes_lexer->contents_length)
    {
        if (hermes_lexer->current_char == ' ' || (int) hermes_lexer->current_char == 10 || (int) hermes_lexer->current_char == 13)
            hermes_lexer_skip_whitespace(hermes_lexer);

        if (isdigit(hermes_lexer->current_char))
            return hermes_lexer_collect_number(hermes_lexer);

        if (isalnum(hermes_lexer->current_char))
            return hermes_lexer_collect_id(hermes_lexer);

        if (hermes_lexer->current_char == '+')
        {
            char* value = hermes_lexer_current_charstr(hermes_lexer);

            int type = TOKEN_PLUS;
            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '=')  // +=
            {
                type = TOKEN_PLUS_EQUALS;
                value = realloc(value, strlen(value) + 2);
                char* strchar = hermes_lexer_current_charstr(hermes_lexer);
                strcat(value, strchar);
                free(strchar);

                hermes_lexer_advance(hermes_lexer);
            }

            return init_token(type, value);
        }

        if (hermes_lexer->current_char == '-')
        {
            char* value = hermes_lexer_current_charstr(hermes_lexer);

            int type = TOKEN_MINUS;
            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '=')  // -=
            {
                type = TOKEN_MINUS_EQUALS;
                value = realloc(value, strlen(value) + 2);
                char* strchar = hermes_lexer_current_charstr(hermes_lexer);
                strcat(value, strchar);
                free(strchar);

                hermes_lexer_advance(hermes_lexer);
            }

            return init_token(type, value);
        }

        if (hermes_lexer->current_char == '*')
        {
            char* value = hermes_lexer_current_charstr(hermes_lexer);

            int type = TOKEN_STAR;
            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '=')  // *=
            {
                type = TOKEN_STAR_EQUALS;
                value = realloc(value, strlen(value) + 2);
                char* strchar = hermes_lexer_current_charstr(hermes_lexer);
                strcat(value, strchar);
                free(strchar);

                hermes_lexer_advance(hermes_lexer);
            }

            return init_token(type, value);
        }

        if (hermes_lexer->current_char == '&')
        {
            char* value = hermes_lexer_current_charstr(hermes_lexer);

            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '&')  // &&
            {
                value = realloc(value, strlen(value) + 2);
                char* strchar = hermes_lexer_current_charstr(hermes_lexer);
                strcat(value, strchar);
                free(strchar);

                hermes_lexer_advance(hermes_lexer);

                return init_token(TOKEN_AND, value);
            }
        }

        if (hermes_lexer->current_char == '=')
        {
            char* value = hermes_lexer_current_charstr(hermes_lexer);

            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '=')  // ==
            {
                value = realloc(value, strlen(value) + 2);
                char* strchar = hermes_lexer_current_charstr(hermes_lexer);
                strcat(value, strchar);
                free(strchar);

                hermes_lexer_advance(hermes_lexer);

                token_T* token = init_token(TOKEN_EQUALS_EQUALS, value);
                free(value);
                return token;
            }
            else
            {
                token_T* token = init_token(TOKEN_EQUALS, value);
                free(value);
                return token;
            }
        }

        if (hermes_lexer->current_char == '!')
        {
            char* value = hermes_lexer_current_charstr(hermes_lexer);

            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '=')  // !=
            {
                value = realloc(value, strlen(value) + 2);
                char* strchar = hermes_lexer_current_charstr(hermes_lexer);
                strcat(value, strchar);
                free(strchar);

                hermes_lexer_advance(hermes_lexer);

                token_T* token = init_token(TOKEN_NOT_EQUALS, value);
                free(value);
                return token;
            }

            token_T* token = init_token(TOKEN_NOT, value);
            free(value);
            return token;
        }

        if (hermes_lexer->current_char == '#')
        {
            hermes_lexer_advance(hermes_lexer);
            hermes_lexer_skip_inline_comment(hermes_lexer);
            continue;
        }

        if (hermes_lexer->current_char == '/')
        {
            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '/')
            {
                hermes_lexer_advance(hermes_lexer);
                hermes_lexer_skip_inline_comment(hermes_lexer);
                continue;
            }
            else
            if (hermes_lexer->current_char == '*')
            {
                hermes_lexer_advance(hermes_lexer);
                hermes_lexer_skip_block_comment(hermes_lexer);
                continue;
            }
            else
            if (hermes_lexer->current_char != '/')
            {
                return init_token(TOKEN_DIV, "/");
            }
        }

        switch(hermes_lexer->current_char)
        {
            case '"': return hermes_lexer_collect_string(hermes_lexer); break;
            case '\'': return hermes_lexer_collect_char(hermes_lexer); break;
            case '{': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_LBRACE); break;
            case '}': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_RBRACE); break;
            case '[': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_LBRACKET); break;
            case ']': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_RBRACKET); break;
            case '(': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_LPAREN); break;
            case ')': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_RPAREN); break;
            case ';': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_SEMI); break;
            case ',': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_COMMA); break;
            case '%': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_PERCENTAGE); break;
            case '.': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_DOT); break;
            case '<': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_LESS_THAN); break;
            case '>': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_LARGER_THAN); break;
            case '@': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_ANON_ID); break;
            case '?': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_QUESTION); break;
            case ':': return hermes_lexer_advance_with_token(hermes_lexer, TOKEN_COLON); break;
            case '\0': return init_token(TOKEN_EOF, "\0"); break;
            default: printf("[Line %d] Unexpected %c\n", hermes_lexer->line_n, hermes_lexer->current_char); exit(1); break;
        }
    }

    return init_token(TOKEN_EOF, "\0");
}

/**
 * Advances and also returns a token
 *
 * @param hermes_lexer_T* hermes_lexer
 * @param int type
 *
 * @return token_T*
 */
token_T* hermes_lexer_advance_with_token(hermes_lexer_T* hermes_lexer, int type)
{
    char* value = hermes_lexer_current_charstr(hermes_lexer);
    hermes_lexer_advance(hermes_lexer);
    token_T* token = init_token(type, value);
    free(value);

    // ensures that the lexer state is correct if exited through this function.
    hermes_lexer_skip_whitespace(hermes_lexer);

    return token;
}

/**
 * Advance, move to the next char
 *
 * @param hermes_lexer_T* hermes_lexer
 */
void hermes_lexer_advance(hermes_lexer_T* hermes_lexer)
{
    if (hermes_lexer->current_char == '\n' || hermes_lexer->current_char == 10)
        hermes_lexer->line_n += 1;

    if (hermes_lexer->current_char != '\0' && hermes_lexer->char_index < hermes_lexer->contents_length)
    {
        hermes_lexer->char_index += 1;
        hermes_lexer->current_char = hermes_lexer->contents[hermes_lexer->char_index];
    }
    else
    {
        hermes_lexer->current_char = '\0';
    }
}

/**
 * Expect the current char to be `c`, if it is not, throw an error.
 *
 * @param hermes_lexer_T* hermes_lexer
 * @param char c
 */
void hermes_lexer_expect_char(hermes_lexer_T* hermes_lexer, char c)
{
    if (hermes_lexer->current_char != c)
    {
        printf("Error: [Line %d] Lexer expected the current char to be `%c`, but it was `%c`.", c, hermes_lexer->current_char, hermes_lexer->line_n);
        exit(1);
    }
}

/**
 * Move to the next char until there is no more whitespace.
 *
 * @param hermes_lexer_T* hermes_lexer
 */
void hermes_lexer_skip_whitespace(hermes_lexer_T* hermes_lexer)
{
    while (hermes_lexer->current_char == ' ' || (int) hermes_lexer->current_char == 10 || (int) hermes_lexer->current_char == 13)
        hermes_lexer_advance(hermes_lexer);
}

/**
 * Skip an inline comment
 *
 * @param hermes_lexer_T* hermes_lexer
 */
void hermes_lexer_skip_inline_comment(hermes_lexer_T* hermes_lexer)
{
    while (hermes_lexer->current_char != '\n' && hermes_lexer->current_char != 10)
        hermes_lexer_advance(hermes_lexer);
}

/**
 * Skip a block comment
 *
 * @param hermes_lexer_T* hermes_lexer
 */
void hermes_lexer_skip_block_comment(hermes_lexer_T* hermes_lexer)
{
    while (1)
    {
        hermes_lexer_advance(hermes_lexer);

        if (hermes_lexer->current_char == '*')
        {
            hermes_lexer_advance(hermes_lexer);

            if (hermes_lexer->current_char == '/')
            {
                hermes_lexer_advance(hermes_lexer);
                return;
            }
        }
    }
}

/**
 * Collect a string token
 *
 * @param hermes_lexer_T* hermes_lexer
 *
 * @return token_T*
 */
 token_T* hermes_lexer_collect_string(hermes_lexer_T* hermes_lexer)
 {
     hermes_lexer_expect_char(hermes_lexer, '"');
     hermes_lexer_advance(hermes_lexer);

     size_t initial_index = hermes_lexer->char_index;

     while (hermes_lexer->current_char != '"')
     {
         if (hermes_lexer->current_char == '\0')
         {
             printf("[Line %d] Missing closing quotation mark\n", hermes_lexer->line_n); exit(1);
         }

         hermes_lexer_advance(hermes_lexer);
     }

     size_t length = hermes_lexer->char_index - initial_index + 1;
     char* buffer = calloc(length, sizeof(char));
     memcpy(buffer, &hermes_lexer->contents[initial_index], length);
     buffer[length - 1] = '\0';

     hermes_lexer_advance(hermes_lexer);

     token_T* token = init_token(TOKEN_STRING_VALUE, buffer);
     free(buffer);

     return token;
 }

/**
 * Collect a char token
 *
 * @param hermes_lexer_T* hermes_lexer
 *
 * @return token_T*
 */
token_T* hermes_lexer_collect_char(hermes_lexer_T* hermes_lexer)
{
    hermes_lexer_expect_char(hermes_lexer, '\'');
    hermes_lexer_advance(hermes_lexer);
    char* buffer = calloc(1, sizeof(char));
    buffer[0] = '\0';

    int c = 0;

    while (hermes_lexer->current_char != '\'')
    {
        if (c > 1)
        {
            printf("Error: [Line %d] Chars can only contain one character\n", hermes_lexer->line_n);
            exit(1);
        }

        char* strchar = hermes_lexer_current_charstr(hermes_lexer);
        buffer = realloc(buffer, strlen(buffer) + 2);
        strcat(buffer, strchar);
        free(strchar);

        hermes_lexer_advance(hermes_lexer);

        c++;
    }

    hermes_lexer_advance(hermes_lexer);

    return init_token(TOKEN_CHAR_VALUE, buffer);
}

/**
 * Collect a numeric token
 *
 * @param hermes_lexer_T* hermes_lexer
 *
 * @return token_T*
 */
token_T* hermes_lexer_collect_number(hermes_lexer_T* hermes_lexer)
{
    int type = TOKEN_INTEGER_VALUE;

    char* buffer = calloc(1, sizeof(char));
    buffer[0] = '\0';

    while (isdigit(hermes_lexer->current_char))
    {
        char* strchar = hermes_lexer_current_charstr(hermes_lexer);
        buffer = realloc(buffer, strlen(buffer) + 2);
        strcat(buffer, strchar);
        free(strchar);

        hermes_lexer_advance(hermes_lexer);
    }

    if (hermes_lexer->current_char == '.')
    {
        char* strchar = hermes_lexer_current_charstr(hermes_lexer);
        buffer = realloc(buffer, strlen(buffer) + 2);
        strcat(buffer, strchar);
        free(strchar);

        hermes_lexer_advance(hermes_lexer);

        type = TOKEN_FLOAT_VALUE;

        while (isdigit(hermes_lexer->current_char))
        {
            char* strchar = hermes_lexer_current_charstr(hermes_lexer);
            buffer = realloc(buffer, strlen(buffer) + 2);
            strcat(buffer, strchar);
            free(strchar);

            hermes_lexer_advance(hermes_lexer);
        }
    }

    return init_token(type, buffer);
}

/**
 * Collect an ID token
 *
 * @param hermes_lexer_T* hermes_lexer
 *
 * @return token_T*
 */
token_T* hermes_lexer_collect_id(hermes_lexer_T* hermes_lexer)
{
    size_t initial_index = hermes_lexer->char_index;

    while (isalnum(hermes_lexer->current_char) || hermes_lexer->current_char == '_')
    {
        hermes_lexer_advance(hermes_lexer);
    }

    size_t length = hermes_lexer->char_index - initial_index + 1;
    char* buffer = calloc(length, sizeof(char));
    memcpy(buffer, &hermes_lexer->contents[initial_index], length);
    buffer[length - 1] = '\0';

    token_T* token = init_token(TOKEN_ID, buffer);
    free(buffer);

    return token;
}

/**
 * Returns the current char of the hermes_lexer as a string
 *
 * @param hermes_lexer_T* hermes_lexer
 */
char* hermes_lexer_current_charstr(hermes_lexer_T* hermes_lexer)
{
    char* str = calloc(2, sizeof(char));
    str[0] = hermes_lexer->current_char;
    str[1] = '\0';

    return str;
}
