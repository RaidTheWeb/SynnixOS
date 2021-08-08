#include "include/main.h"
#include "include/test_hermes_lexer.h"
#include "include/test_hermes_parser.h"
#include "include/test_hermes_runtime.h"
#include "include/test_hermes_output.h"


int main(int argc, char* argv[])
{
    const struct CMUnitTest tests [] =
    {
        cmocka_unit_test(test_hermes_lexer_behavior),
        cmocka_unit_test(test_hermes_parser_variable_definition_does_not_crash),
        cmocka_unit_test(test_hermes_parser_function_definition_does_not_crash),
        cmocka_unit_test(test_hermes_runtime_does_not_crash),
        cmocka_unit_test(test_hermes_runtime_lists_in_lists),
        cmocka_unit_test(test_hermes_runtime_list_add),
        cmocka_unit_test(test_hermes_runtime_this),
        cmocka_unit_test(test_hermes_runtime_assert),
        cmocka_unit_test(test_hermes_runtime_to_string),
        cmocka_unit_test(test_hermes_output)
    };

    int count_fail_tests =
        cmocka_run_group_tests (tests, NULL, NULL);

    return count_fail_tests;
}
