#ifndef HERMES_BUILTINS_H
#define HERMES_BUILTINS_H
#include "AST.h"
#include "hermes_runtime.h"

void init_builtins(runtime_T* runtime);

AST_T* hermes_builtin_function_print(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_stdoutbuffer(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_aprint(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_include(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_wad(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_lad(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_fopen(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_fclose(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_fputs(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_input(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_char_to_bin(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_char_to_oct(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_char_to_dec(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_char_to_hex(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_time(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_dload(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_free(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_visit(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_strrev(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

AST_T* hermes_builtin_function_ssh(runtime_T* runtime, AST_T* self, dynamic_list_T* args);

static AST_T* INITIALIZED_NOOP;
#endif
