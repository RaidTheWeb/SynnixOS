#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <readline.h>

#include "calculator.h"

int main(int argc, char* argv[])
{
    byte_8 result;
    simple_queue_t output;
    simple_stack_t ops;

    if(argc > 1) {
        queue_init(&output);
        stack_init(&ops);

        shunting_yard(argv[1], &ops, &output);

        result = compute_rpn(&output);
        printf("%lld\n", result);
        return 0;
    }

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