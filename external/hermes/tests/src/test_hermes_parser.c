#include "include/main.h"
#include "../../src/include/hermes_parser.h"
#include "../../src/include/io.h"
#include <string.h>


void test_hermes_parser_variable_definition_does_not_crash(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/test_parser.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    hermes_parser_parse(parser, (void*) 0);
    assert_true(parser != NULL);
}

void test_hermes_parser_function_definition_does_not_crash(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/dosomething.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    hermes_parser_parse(parser, (void*) 0);
    assert_true(parser != NULL);
}
