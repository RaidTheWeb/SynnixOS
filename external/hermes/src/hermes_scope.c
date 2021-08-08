#include "include/hermes_scope.h"


hermes_scope_T* init_hermes_scope(unsigned int global)
{
    hermes_scope_T* hermes_scope = calloc(1, sizeof(struct HERMES_SCOPE_STRUCT));
    hermes_scope->variable_definitions = init_dynamic_list(sizeof(struct AST_STRUCT*));
    hermes_scope->function_definitions = init_dynamic_list(sizeof(struct AST_STRUCT*));
    hermes_scope->global = global;

    return hermes_scope;
}

void hermes_scope_free(hermes_scope_T* hermes_scope)
{
    if (hermes_scope->variable_definitions)
    {
        for (int i = 0; i < hermes_scope->variable_definitions->size; i++)
        {
            AST_T* vardef = (AST_T*) hermes_scope->variable_definitions->items[i];

            if (vardef->variable_name)
                free(vardef->variable_name);

            if (vardef->variable_type)
                ast_free(vardef->variable_type);

            if (vardef->variable_value)
                ast_free(vardef->variable_value);

            free(vardef);
        }

        free(hermes_scope->variable_definitions->items);
        free(hermes_scope->variable_definitions);
        hermes_scope->variable_definitions = (void*)0;
    }

    if (hermes_scope->function_definitions)
    {
        for (int i = 0; i < hermes_scope->function_definitions->size; i++)
        {
            AST_T* fdef = (AST_T*) hermes_scope->function_definitions->items[i];

            if (fdef->function_definition_type)
                ast_free(fdef->function_definition_type);

            if (fdef->function_name)
                free(fdef->function_name); 

            if (fdef->function_definition_arguments)
            {
                for (int x = 0; x < fdef->function_definition_arguments->size; x++)
                {
                    AST_T* vardef = (AST_T*) fdef->function_definition_arguments->items[x];

                    if (vardef == fdef)
                        continue;

                    if (vardef->variable_name)
                        free(vardef->variable_name);

                    if (vardef->variable_type)
                        ast_free(vardef->variable_type);

                    if (vardef->variable_value)
                        ast_free(vardef->variable_value);

                    free(vardef);
                }

                free(fdef->function_definition_arguments->items);
                free(fdef->function_definition_arguments);
                fdef->function_definition_arguments = (void*) 0; 
            }

            if (fdef->function_definition_body)
            {
                /*if (fdef->function_definition_body->scope)
                {
                    if ((hermes_scope_T*)fdef->function_definition_body->scope != hermes_scope)
                        hermes_scope_free((hermes_scope_T*)fdef->function_definition_body->scope);
                }*/

                ast_free(fdef->function_definition_body);
            }

            if (fdef->composition_children)
            {
                for (int i = 0; i < fdef->composition_children->size; i++)
                {
                    if ((AST_T*)fdef->composition_children->items[i] != fdef)
                        ast_free((AST_T*)fdef->composition_children->items[i]);
                }

                free(fdef->composition_children->items);
                free(fdef->composition_children);
                fdef->composition_children = (void*) 0;
            }

            free(fdef);
        } 

        free(hermes_scope->function_definitions->items);
        free(hermes_scope->function_definitions);
        hermes_scope->function_definitions = (void*) 0;
    }

    free(hermes_scope);
}

/*static void free_variable_definition(void* n)
{
    AST_T* node = (AST_T*) n;
    ast_free(node);
}

static void free_function_definition(void* n)
{
    AST_T* node = (AST_T*) n;
    ast_free(node);
}*/

void hermes_scope_clear_variable_definitions(hermes_scope_T* scope)
{
    for (int i = 0; i < scope->variable_definitions->size; i++)
    {
        AST_T* node = (AST_T*) scope->variable_definitions->items[i];
        ast_free(node);
    }

    scope->variable_definitions->size = 0;
}

void hermes_scope_clear_function_definitions(hermes_scope_T* scope)
{
    for (int i = 0; i < scope->function_definitions->size; i++)
    {
        AST_T* node = (AST_T*) scope->function_definitions->items[i];
        ast_free(node);
    }

    scope->function_definitions->size = 0;
}
