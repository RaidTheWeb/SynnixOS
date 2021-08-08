#ifndef HERMES_STRING_UTILS_H
#define HERMES_STRING_UTILS_H
#include <stdlib.h>
char* hermes_char_to_string(char c);

char* hermes_init_str(const char* value);

char* hermes_get_stdin(const char* printstr);

char *hermes_strrev(char *instr);
#endif
