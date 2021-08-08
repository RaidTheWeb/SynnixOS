#include "include/main.h"
#include "include/hermes_lexer.h"
#include "include/hermes_parser.h"
#include "include/hermes_runtime.h"
#include "include/hermes_cleanup.h"
#include "include/string_utils.h"
#include "include/io.h"
#include <signal.h>


volatile unsigned int interactive;


void int_handler(int sig)
{
    interactive = 0;
}

int main(int argc, char* argv[])
{
    interactive = 0;
    signal(SIGINT, int_handler);

    runtime_T* runtime = init_runtime();
    hermes_lexer_T* lexer = (void*)0;
    hermes_parser_T* parser = (void*)0;
    AST_T* node = (void*)0;

    if (argc < 2)
    {
        interactive = 1;
        printf("---- * Interactive Hermes Shell * ----\n");

        while (interactive)
        {
            char* str = hermes_get_stdin(">: ");

            lexer = init_hermes_lexer(str);

            parser = init_hermes_parser(lexer);
            node = hermes_parser_parse(parser, (void*) 0);
            runtime_visit(runtime, node);
        }

        hermes_cleanup(lexer, parser, runtime, node);

        printf("---- * Interactive Shell Terminated. * ----\n");

        return 0;
    }

    lexer = init_hermes_lexer(hermes_read_file(argv[1]));
    parser = init_hermes_parser(lexer);
    node = hermes_parser_parse(parser, (void*) 0);
    runtime_visit(runtime, node);

    hermes_cleanup(lexer, parser, runtime, node);

    return 0;
}
