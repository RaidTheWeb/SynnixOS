#ifndef HERMES_RUNTIME_H
#define HERMES_RUNTIME_H
#include "hermes_scope.h"
#include "dynamic_list.h"

typedef struct RUNTIME_STRUCT
{
    hermes_scope_T* scope;
    dynamic_list_T* list_methods;
    char* stdout_buffer;
} runtime_T;

AST_T* runtime_register_global_function(runtime_T* runtime, char* fname, struct AST_STRUCT* (*fptr)(struct RUNTIME_STRUCT* runtime, struct AST_STRUCT* self, dynamic_list_T* args));

AST_T* runtime_register_global_variable(runtime_T* runtime, char* vname, char* vval);

runtime_T* init_runtime();

AST_T* runtime_visit(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_variable(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_variable_definition(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_variable_assignment(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_variable_modifier(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_function_definition(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_function_call(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_null(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_string(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_char(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_float(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_object(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_enum(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_list(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_boolean(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_integer(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_compound(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_type(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_attribute_access(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_list_access(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_binop(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_unop(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_noop(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_break(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_continue(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_return(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_if(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_ternary(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_while(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_for(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_new(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_iterate(runtime_T* runtime, AST_T* node);

AST_T* runtime_visit_assert(runtime_T* runtime, AST_T* node);

hermes_scope_T* get_scope(runtime_T* runtime, AST_T* node);

void hermes_runtime_buffer_stdout(runtime_T* runtime, const char* buffer);

void runtime_expect_args(dynamic_list_T* in_args, int argc, int args[]);

AST_T* get_variable_definition_by_name(runtime_T* runtime, hermes_scope_T* scope, char* variable_name);
#endif
