#ifndef HERMES_AST_H
#define HERMES_AST_H
#include <stdio.h>
#include "dynamic_list.h"
#include "token.h"
#include "data_type.h"


struct RUNTIME_STRUCT;

typedef struct AST_STRUCT
{
    enum {
        AST_OBJECT,
        AST_ENUM,
        AST_VARIABLE,
        AST_VARIABLE_DEFINITION,
        AST_VARIABLE_ASSIGNMENT,
        AST_VARIABLE_MODIFIER,
        AST_FUNCTION_DEFINITION,
        AST_FUNCTION_CALL,
        AST_NULL,
        AST_STRING,
        AST_CHAR,
        AST_FLOAT,
        AST_LIST,
        AST_BOOLEAN,
        AST_INTEGER,
        AST_ANY,
        AST_COMPOUND,
        AST_TYPE,
        AST_BINOP,
        AST_UNOP,
        AST_NOOP,
        AST_BREAK,
        AST_RETURN,
        AST_CONTINUE,
        AST_TERNARY,
        AST_IF,
        AST_ELSE,
        AST_WHILE,
        AST_FOR,
        AST_ATTRIBUTE_ACCESS,
        AST_LIST_ACCESS,
        AST_NEW,
        AST_ITERATE,
        AST_ASSERT
    } type;
    
    struct AST_STRUCT* function_call_expr;

    int line_n;
    int int_value;
    long int long_int_value;
    unsigned int boolean_value;
    unsigned int is_object_child;
    float float_value;
    char char_value;
    char* string_value;
    data_type_T* type_value;
    char* variable_name;
    struct AST_STRUCT* variable_value;
    struct AST_STRUCT* variable_type;
    struct AST_STRUCT* variable_assignment_left;
    char* function_name;

    /* ==== binop ==== */
    struct AST_STRUCT* binop_left;
    struct AST_STRUCT* binop_right;
    token_T* binop_operator;

    /* ==== unop ==== */
    struct AST_STRUCT* unop_right;
    token_T* unop_operator;

    /* ==== for ==== */
    struct AST_STRUCT* for_init_statement;
    struct AST_STRUCT* for_test_expr;
    struct AST_STRUCT* for_update_statement;
    struct AST_STRUCT* for_body;

    dynamic_list_T* compound_value;
    dynamic_list_T* function_call_arguments;
    dynamic_list_T* function_definition_arguments;
    dynamic_list_T* object_children;
    dynamic_list_T* enum_children;
    void* object_value;
    dynamic_list_T* list_children;
    dynamic_list_T* function_definitions;
    dynamic_list_T* composition_children;
    struct AST_STRUCT* function_definition_body;
    struct AST_STRUCT* function_definition_type;

    /* ==== if ==== */
    struct AST_STRUCT* if_expr;
    struct AST_STRUCT* if_body;
    struct AST_STRUCT* if_otherwise;
    struct AST_STRUCT* else_body;
    
    /* ==== ternary ==== */
    struct AST_STRUCT* ternary_expr;
    struct AST_STRUCT* ternary_body;
    struct AST_STRUCT* ternary_else_body;

    struct AST_STRUCT* while_expr;
    struct AST_STRUCT* while_body;
    struct AST_STRUCT* return_value;
    struct AST_STRUCT* list_access_pointer;
    struct AST_STRUCT* saved_function_call;
    struct AST_STRUCT* new_value;
    struct AST_STRUCT* iterate_iterable;
    struct AST_STRUCT* iterate_function;
    struct AST_STRUCT* ast;
    struct AST_STRUCT* parent;
    struct AST_STRUCT* assert_expr;
    
    struct hermes_scope_T* scope;

    struct AST_STRUCT* (*fptr)(struct RUNTIME_STRUCT* runtime, struct AST_STRUCT* self, dynamic_list_T* args);
} AST_T;

AST_T* init_ast(int type);
AST_T* init_ast_with_line(int type, int line_n);

void _ast_free(void* ast);
void ast_free(AST_T* ast);

AST_T* ast_copy(AST_T* ast);
AST_T* ast_copy_object(AST_T* ast);
AST_T* ast_copy_variable(AST_T* ast);
AST_T* ast_copy_variable_definition(AST_T* ast);
AST_T* ast_copy_function_definition(AST_T* ast);
AST_T* ast_copy_string(AST_T* ast);
AST_T* ast_copy_char(AST_T* ast);
AST_T* ast_copy_float(AST_T* ast);
AST_T* ast_copy_list(AST_T* ast);
AST_T* ast_copy_boolean(AST_T* ast);
AST_T* ast_copy_integer(AST_T* ast);
AST_T* ast_copy_compound(AST_T* ast);
AST_T* ast_copy_type(AST_T* ast);
AST_T* ast_copy_attribute_access(AST_T* ast);
AST_T* ast_copy_return(AST_T* ast);
AST_T* ast_copy_variable_assignment(AST_T* ast);
AST_T* ast_copy_variable_modifier(AST_T* ast);
AST_T* ast_copy_function_call(AST_T* ast);
AST_T* ast_copy_null(AST_T* ast);
AST_T* ast_copy_list_access(AST_T* ast);
AST_T* ast_copy_binop(AST_T* ast);
AST_T* ast_copy_if(AST_T* ast);
AST_T* ast_copy_while(AST_T* ast);

char* ast_to_string(AST_T* ast);
char* ast_object_to_string(AST_T* ast);
char* ast_function_definition_to_string(AST_T* ast);
char* ast_function_call_to_string(AST_T* ast);
char* ast_null_to_string(AST_T* ast);
char* ast_float_to_string(AST_T* ast);
char* ast_list_to_string(AST_T* ast);
char* ast_boolean_to_string(AST_T* ast);
char* ast_integer_to_string(AST_T* ast);
char* ast_type_to_string(AST_T* ast);
char* ast_attribute_access_to_string(AST_T* ast);
char* ast_list_access_to_string(AST_T* ast);
char* ast_binop_to_string(AST_T* ast);
char* ast_enum_to_string(AST_T* ast);

#endif
