#ifndef HERMES_SCOPE_H
#define HERMES_SCOPE_H
#include "AST.h"
#include "dynamic_list.h"


typedef struct HERMES_SCOPE_STRUCT
{
    AST_T* owner;
    dynamic_list_T* variable_definitions;
    dynamic_list_T* function_definitions;
    unsigned int global;
} hermes_scope_T;

hermes_scope_T* init_hermes_scope(unsigned int global);

void hermes_scope_free(hermes_scope_T* hermes_scope);

void hermes_scope_clear_variable_definitions(hermes_scope_T* scope);

void hermes_scope_clear_function_definitions(hermes_scope_T* scope);
#endif
