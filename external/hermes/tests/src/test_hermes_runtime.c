#include "include/main.h"
#include "../../src/include/hermes_parser.h"
#include "../../src/include/hermes_runtime.h"
#include "../../src/include/io.h"
#include <string.h>


void test_hermes_runtime_does_not_crash(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/test_runtime.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();
    runtime_visit(runtime, node);

    assert_true(runtime != NULL);
}

void test_hermes_runtime_lists_in_lists(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/lists_in_lists.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();
    runtime_visit(runtime, node);

    assert_true(runtime != NULL);
}

void test_hermes_runtime_list_add(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/list_add.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();
    runtime_visit(runtime, node);

    assert_true(runtime != NULL);
}

void test_hermes_runtime_this(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/this.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();

    /*char buf[4096] = { 0 };
    fclose(stdout);
    stdout = fmemopen(buf, sizeof(buf), "w");
    setbuf(stdout, NULL);*/

    runtime_visit(runtime, node);

    //assert_true(strcmp(buf, "Hello\n") == 0);
}

void test_hermes_runtime_assert(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/assert.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();
    runtime_visit(runtime, node);

    assert_true(runtime != NULL);
}

void test_hermes_runtime_to_string(void** state)
{
    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file("sources/to_string.he")
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();
    runtime_visit(runtime, node);

    assert_true(runtime != NULL);
}
