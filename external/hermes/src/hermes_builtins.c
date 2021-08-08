#include "include/hermes_builtins.h"
#include "include/hermes_runtime.h"
#include "include/hermes_lexer.h"
#include "include/hermes_parser.h"
#include "include/string_utils.h"
#include "include/io.h"
#include <string.h>
#include <time.h>

void init_builtins(runtime_T* runtime)
{
  runtime_register_global_variable(runtime, "ver", "1.0.1");

  // GLOBAL FUNCTIONS
  runtime_register_global_function(runtime, "include", hermes_builtin_function_include);
  runtime_register_global_function(runtime, "wad", hermes_builtin_function_wad);
  runtime_register_global_function(runtime, "lad", hermes_builtin_function_lad);
  runtime_register_global_function(runtime, "print", hermes_builtin_function_print);
  runtime_register_global_function(runtime, "stdoutbuffer", hermes_builtin_function_stdoutbuffer);
  runtime_register_global_function(runtime, "aprint", hermes_builtin_function_aprint);
  runtime_register_global_function(runtime, "fopen", hermes_builtin_function_fopen);
  runtime_register_global_function(runtime, "fclose", hermes_builtin_function_fclose);
  runtime_register_global_function(runtime, "fputs", hermes_builtin_function_fputs);
  runtime_register_global_function(runtime, "input", hermes_builtin_function_input);
  runtime_register_global_function(runtime, "char_to_bin", hermes_builtin_function_char_to_bin);
  runtime_register_global_function(runtime, "char_to_oct", hermes_builtin_function_char_to_oct);
  runtime_register_global_function(runtime, "char_to_dec", hermes_builtin_function_char_to_dec);
  runtime_register_global_function(runtime, "char_to_hex", hermes_builtin_function_char_to_hex);
  runtime_register_global_function(runtime, "time", hermes_builtin_function_time);
  runtime_register_global_function(runtime, "free", hermes_builtin_function_free);
  runtime_register_global_function(runtime, "visit", hermes_builtin_function_visit);
  runtime_register_global_function(runtime, "strrev", hermes_builtin_function_strrev);
}

/**
 * Simple print implementation.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_print(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    for (int i = 0; i < args->size; i++)
    {
        AST_T* ast_arg = (AST_T*) args->items[i];
        char* str = ast_to_string(ast_arg);

        if (str == (void*)0)
        {
            printf("(void*)0\n");
        }
        else
        {
            printf("%s\n", str);
            free(str);
        }
    }

    return INITIALIZED_NOOP;
}

AST_T* hermes_builtin_function_stdoutbuffer(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    for (int i = 0; i < args->size; i++)
    {
        AST_T* ast_arg = (AST_T*) runtime_visit(runtime, args->items[i]);
        char* str = ast_to_string(ast_arg);

        if (str == (void*)0)
        {
            hermes_runtime_buffer_stdout(runtime, "(void*)0\n");
        }
        else
        {
            str = realloc(str, (strlen(str) + 2) * sizeof(char));
            strcat(str, "\n");
            hermes_runtime_buffer_stdout(runtime, str);
            free(str);
        }
    }

    return INITIALIZED_NOOP;
}

/**
 * Print the adress of a value
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_aprint(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    for (int i = 0; i < args->size; i++)
        printf("%p\n", (AST_T*) args->items[i]);

    return INITIALIZED_NOOP;
}

/**
 * Method for including other scripts, this will return the root node
 * as a compound.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_include(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_STRING});

    AST_T* ast_str = (AST_T*) args->items[0];
    char* filename = ast_str->string_value;

    hermes_lexer_T* lexer = init_hermes_lexer(hermes_read_file(filename));
    hermes_parser_T* parser = init_hermes_parser(lexer);
    AST_T* node = hermes_parser_parse(parser, (void*) 0);

    hermes_lexer_free(lexer);

    return node;
}

/**
 * Builtin method to dump an AST node to disk, serialized.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_wad(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 2, (int[]) {AST_COMPOUND, AST_STRING});

    AST_T* ast_compound = (AST_T*) args->items[0];
    AST_T* ast_string = (AST_T*) args->items[1];

    char* filename = ast_string->string_value;

    FILE *outfile;

    const char* filename_template = "%s.dat";
    char* fname = calloc(strlen(filename) + strlen(filename_template) + 1, sizeof(char));
    sprintf(fname, filename_template, filename);

    outfile = fopen(fname, "w");

    if (outfile == NULL)
    {
        fprintf(stderr, "Could not open %s\n", fname);
        free(fname);
        exit(1);
    }

    // write struct to file
    int r = fwrite (&*ast_compound, sizeof(struct AST_STRUCT), 1, outfile);

    if(r != 0)
    {
        // silence
    }
    else
    {
        printf("Could not write to %s\n", fname);
    }

    free(fname);

    fclose(outfile);

    return ast_compound;
}

/**
 * Built-in function to load a compound AST from disk
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_lad(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_STRING});

    AST_T* ast_string = (AST_T*) args->items[0];

    char* filename = ast_string->string_value;

    const char* filename_template = "%s.dat";
    char* fname = calloc(strlen(filename) + strlen(filename_template) + 1, sizeof(char));
    sprintf(fname, filename_template, filename);

    FILE *infile;
    struct AST_STRUCT input;

    infile = fopen(fname, "r");
    if (infile == NULL)
    {
        fprintf(stderr, "Error reading %s\n", fname);
        free(fname);
        exit(1);
    }

    // read file contents till end of file
    while(fread(&input, sizeof(struct AST_STRUCT), 1, infile))
        printf("...\n");

    // close file
    fclose (infile);

    AST_T* loaded = &input;

    return loaded;
}

static AST_T* object_file_function_read(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    FILE* f = self->object_value;

    char* buffer = 0;
    long length;

    if (f)
    {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = calloc (length, length);

        if (buffer)
            fread (buffer, 1, length, f);
    }

    AST_T* ast_string = init_ast(AST_STRING);
    ast_string->string_value = buffer;

    return ast_string;
}

/**
 * Built-in function to open file.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_fopen(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 2, (int[]) {AST_STRING, AST_STRING});

    char* filename = ((AST_T*)args->items[0])->string_value;
    char* mode = ((AST_T*)args->items[1])->string_value;

    FILE* f = fopen(filename, mode);

    AST_T* ast_obj = init_ast(AST_OBJECT);
    ast_obj->variable_type = init_ast(AST_TYPE);
    ast_obj->variable_type->type_value = init_data_type_as(DATA_TYPE_OBJECT);
    ast_obj->object_value = f;

    AST_T* fdef_read = init_ast(AST_FUNCTION_DEFINITION);
    fdef_read->function_name = "read";
    fdef_read->fptr = object_file_function_read;

    ast_obj->function_definitions = init_dynamic_list(sizeof(struct AST_STRUCT*));
    dynamic_list_append(ast_obj->function_definitions, fdef_read);

    return ast_obj;
}

/**
 * Built-in function to close file.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_fclose(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_OBJECT});

    AST_T* return_ast = init_ast(AST_INTEGER);
    FILE* f = (FILE*) ((AST_T*)args->items[0])->object_value;
    return_ast->int_value = 1;
    fclose(f);

    return return_ast;
}

/**
 * Built-in function to write string to file.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_fputs(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 2, (int[]) {AST_STRING, AST_OBJECT});

    AST_T* return_ast = init_ast(AST_INTEGER);
    return_ast->int_value = 1;

    char* line = ((AST_T*)args->items[0])->string_value;
    FILE* f = (FILE*) ((AST_T*)args->items[1])->object_value;

    fputs(line, f);

    return return_ast;
}

/**
 * Built-in function to read user input from stdin.
 *
 * @param AST_T* self
 * @param dynamic_list_T* args
 *
 * @return AST_T*
 */
AST_T* hermes_builtin_function_input(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    char* str;
    int c;
    int i;
    int size = 10;

    str = malloc(size * sizeof(char));

    if (args->size > 0)
        printf("%s", ((AST_T*)args->items[0])->string_value);

    for(i = 0; (c = getchar()) != '\n' && c != EOF; ++i)
    {
        if(i == size)
        {
            size = 2*size;
            str = realloc(str, size*sizeof(char));

            if(str == NULL)
            {
                printf("Cannot reallic string.\n");
                exit(-1);
            }
        }

        str[i] = c;
    }

    if(i == size)
    {
        str = realloc(str, (size+1)*sizeof(char));

        if(str == NULL)
        {
            printf("Cannot realloc string.\n");
            exit(-1);
        }

    }

    str[i] = '\0';

    AST_T* ast = init_ast(AST_STRING);
    ast->string_value = str;

    return ast;
}


static char* my_itoa(int num, char *str)
{
    if(str == NULL)
        return NULL;

    sprintf(str, "%d", num);
    return str;
}

AST_T* hermes_builtin_function_char_to_bin(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_CHAR});

    AST_T* ast_char = args->items[0];
    char c = ast_char->char_value;

    char* tmp_buffer = calloc(8, sizeof(char));
    int i;
    for(i=0;i<7;i++)
    {
        char* str = calloc(2, sizeof(char));
        my_itoa(c%2, str);
        strcat(tmp_buffer, str);
        c=c/2;
    }

    char* output = calloc(8, sizeof(char));

    for (int i = 8; i >= 0; i--)
    {
        char charv = tmp_buffer[i];
        char* str = hermes_char_to_string(charv);
        strcat(output, str);
    }

    free(tmp_buffer);

    AST_T* ast_string = init_ast(AST_STRING);
    ast_string->string_value = calloc(strlen(output) + 1, sizeof(char));
    strcpy(ast_string->string_value, output);

    return ast_string;
}

AST_T* hermes_builtin_function_char_to_oct(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_CHAR});

    AST_T* ast_char = args->items[0];
    char c = ast_char->char_value;

    char* tmp_buffer = calloc(4, sizeof(char));
    int i;
    for(i = 0; i < 3; i++)
    {
        char* str = calloc(2, sizeof(char));
        my_itoa(c%8, str);
        strcat(tmp_buffer, str);
        c=c/8;
    }

    char* output = calloc(4, sizeof(char));

    for (int i = 4; i >= 0; i--)
    {
        char charv = tmp_buffer[i];
        char* str = hermes_char_to_string(charv);
        strcat(output, str);
    }

    free(tmp_buffer);

    AST_T* ast_string = init_ast(AST_STRING);
    ast_string->string_value = calloc(strlen(output) + 1, sizeof(char));
    strcpy(ast_string->string_value, output);

    return ast_string;
}

AST_T* hermes_builtin_function_char_to_dec(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_CHAR});

    AST_T* ast_char = args->items[0];
    char c = ast_char->char_value;

    AST_T* ast_int = init_ast(AST_INTEGER);
    ast_int->int_value = (int) c;

    return ast_int;
}

AST_T* hermes_builtin_function_char_to_hex(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_CHAR});

    AST_T* ast_char = args->items[0];
    char c = ast_char->char_value;

    char* str = calloc(8, sizeof(char));
    sprintf(str, "%x", c);

    AST_T* ast_string = init_ast(AST_STRING);
    ast_string->string_value = str;

    return ast_string;
}

AST_T* hermes_builtin_function_time(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    AST_T* ast_obj = init_ast(AST_OBJECT);
    ast_obj->variable_type = init_ast(AST_TYPE);
    ast_obj->variable_type->type_value = init_data_type_as(DATA_TYPE_OBJECT);

    AST_T* ast_var = init_ast(AST_VARIABLE_DEFINITION);
    ast_var->variable_name = hermes_init_str("seconds");
    ast_var->variable_type = init_ast(AST_TYPE);
    ast_var->variable_type->type_value = init_data_type_as(DATA_TYPE_INT);
    ast_var->variable_type->type_value->modifiers[0] = DATA_TYPE_MODIFIER_LONG;

    AST_T* ast_int = init_ast(AST_INTEGER);
    ast_int->long_int_value = time(NULL);
    ast_var->variable_value = ast_int;

    dynamic_list_append(ast_obj->object_children, ast_var);

    return ast_obj;
}

AST_T* hermes_builtin_function_free(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    hermes_scope_T* scope = get_scope(runtime, self);

    for (int i = 0; i < args->size; i++)
    {
        AST_T* arg = (AST_T*) args->items[i];

        if (arg->type != AST_VARIABLE)
            continue;

        for (int i = 0; i < scope->variable_definitions->size; i++)
        {
            AST_T* vardef = scope->variable_definitions->items[i];

            if (strcmp(vardef->variable_name, arg->variable_name) == 0)
            {
                dynamic_list_remove(scope->variable_definitions, vardef, (void*)0);
                break;
            }
        }
    }

    return INITIALIZED_NOOP;
}

AST_T* hermes_builtin_function_visit(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    AST_T* arg = (void*)0;

    for (int i = 0; i < args->size; i++)
        arg = runtime_visit(runtime, (AST_T*) args->items[i]);

    return arg;
}

AST_T* hermes_builtin_function_strrev(runtime_T* runtime, AST_T* self, dynamic_list_T* args)
{
    runtime_expect_args(args, 1, (int[]) {AST_STRING});

    char* input_string = ((AST_T*)args->items[0])->string_value;

    char* new_str = hermes_strrev(input_string);

    AST_T* ast_string = init_ast(AST_STRING);
    ast_string->string_value = calloc(strlen(new_str) + 1, sizeof(char));
    strcpy(ast_string->string_value, new_str);

    return ast_string;
}
