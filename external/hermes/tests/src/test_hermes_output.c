#include "include/main.h"
#include "../../src/include/hermes_parser.h"
#include "../../src/include/hermes_runtime.h"
#include "../../src/include/io.h"
#include <string.h>



static char* getstdout(const char* source)
{
    printf("---- * %s * ----\n", source);

    hermes_lexer_T* hermes_lexer = init_hermes_lexer(
        hermes_read_file(source)
    );
    
    hermes_parser_T* parser = init_hermes_parser(hermes_lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);
    runtime_T* runtime = init_runtime();
    runtime_visit(runtime, node);
    assert_true(runtime != NULL);

    // TODO: resolve and find out why this is allocated when it shouldnt.
    //assert_true(runtime->stdout_buffer != (void*)0);

    char* buffer = calloc(strlen(runtime->stdout_buffer) + 1, sizeof(char));
    strcpy(buffer, runtime->stdout_buffer);
    
    // TODO free lexer, parser & runtime here...
    //
    hermes_lexer_free(hermes_lexer);
    free(runtime->stdout_buffer);
    free(runtime);
    free(parser);

    return buffer;
}

void test_hermes_output(void** state)
{
    assert_true(strcmp(getstdout("sources/output/hello_world.he"), "hello world\n") == 0);
    assert_true(strcmp(getstdout("sources/output/print_list.he"), "[ list ]\n") == 0);
    assert_true(strcmp(getstdout("sources/output/print_list_iterate.he"), "pear\nbanana\napple\n") == 0);
    assert_true(strcmp(getstdout("sources/output/null.he"), "1\n1\n") == 0);
    assert_true(strcmp(getstdout("sources/output/fopen.he"), "hello world\n\n") == 0);
    assert_true(strcmp(getstdout("sources/output/compositions.he"), "11\n") == 0);
    assert_true(strcmp(getstdout("sources/output/char.he"), "g\n") == 0);
    assert_true(strcmp(getstdout("sources/output/radix.he"), "1100001\n141\n97\n5f\n") == 0);
    assert_true(strcmp(getstdout("sources/output/definition_in_loop.he"), "1\n1\n1\n1\n") == 0);
    assert_true(strcmp(getstdout("sources/output/object_with_object.he"), "dog\n6\n") == 0);
    assert_true(strcmp(getstdout("sources/output/if.he"), "yes\n") == 0);
    assert_true(strcmp(getstdout("sources/output/else.he"), "it's not\nhello world\n") == 0);
    assert_true(strcmp(getstdout("sources/output/break.he"), "5\n") == 0);
    assert_true(strcmp(getstdout("sources/output/continue.he"), "1\n2\n4\n5\n6\n") == 0);
    assert_true(strcmp(getstdout("sources/output/unary.he"), "-1\n") == 0);
    assert_true(strcmp(getstdout("sources/output/if_no_brace.he"), "10\n") == 0);
    assert_true(strcmp(getstdout("sources/output/ternary.he"), "David\n") == 0);
    assert_true(strcmp(getstdout("sources/output/scope.he"), "else\n") == 0);
    assert_true(strcmp(getstdout("sources/output/math.he"), "5\n5\n50\n12\n50\n2\n5000\n") == 0);
    assert_true(strcmp(getstdout("sources/output/if_and_and.he"), "hello\n") == 0);
    assert_true(strcmp(getstdout("sources/output/for.he"), "0\n1\n2\n") == 0);
    assert_true(strcmp(getstdout("sources/output/iterate_index.he"), "banana\n0\napple\n1\npear\n2\n") == 0);
    assert_true(strcmp(getstdout("sources/output/strrev.he"), "eoD nhoJ\n") == 0);
}
