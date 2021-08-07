#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "calculator.h"

static char buffer[2048];

char* readline(char* prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy)-1] = '\0';
    return cpy;
}

int main(int argc, char* argv[])
{
    byte_8 result;
    simple_queue_t output;
    simple_stack_t ops;

    while(true) {

        char *input = readline("calc> ");

        if(input == NULL) {
            printf("\n");
            break;
        }

        queue_init(&output);
        stack_init(&ops);

        shunting_yard(input, &ops, &output);

        result = compute_rpn(&output);
        printf("%lld\n", result);
    }
    return 0;
}