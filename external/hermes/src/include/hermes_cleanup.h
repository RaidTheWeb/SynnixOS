#ifndef HERMES_CLEANUP_H
#define HERMES_CLEANUP_H
#include "hermes_lexer.h"
#include "hermes_parser.h"
#include "hermes_runtime.h"


void hermes_cleanup(
    hermes_lexer_T* hermes_lexer,
    hermes_parser_T* parser,
    runtime_T* runtime,
    AST_T* node
);
#endif
