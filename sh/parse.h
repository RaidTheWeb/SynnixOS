#pragma once
#ifndef SNX_SH_PARSE_H
#define SNX_SH_PARSE_H

#include "token.h"
#include <list.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/** @file
 * @brief Header file for parser 
 * 
 */

/**
 * @brief Tokens
 * 
 */
enum node_type {
    NODE_PIPELINE,
    // todo:
    NODE_BINOP,
    NODE_ASSIGN,
    NODE_IF,
    NODE_CASE,
    NODE_WHILE,
    NODE_FOR,
    NODE_FUNCTION,
};

/**
 * @brief Operations
 * 
 */
enum node_op {
    NODE_OR,   // ||
    NODE_AND,  // &&
    NODE_THEN, // ;
};

/**
 * @brief Pipeline struct
 * 
 */
struct pipeline;

/**
 * @brief Node struct
 * 
 */
struct node {
    enum node_type type;

    struct pipeline *pipeline; // NODE_PIPELINE

    enum node_op op; // NODE_BINOP
    struct node *left;
    struct node *right; // (+ NODE_ASSIGN)

    char *varname; // NODE_ASSIGN
};

/**
 * @brief Pipeline flags
 * 
 */
enum pipeline_flags {
    PIPELINE_NONE,
    PIPELINE_BACKGROUND = 1,
};

/**
 * @brief Pipeline struct
 * 
 */
struct pipeline {
    list commands;
    pid_t pgrp;
    enum pipeline_flags flags;
};

/**
 * @brief Command struct
 * 
 */
struct command {
    char **argv;
    char *args;
    char *stdin_file;
    char *stdout_file;
    char *stderr_file;
    int stdin_fd, stdout_fd, stderr_fd; // used in eval
    list_node node;
};

/**
 * @brief Parse tokens
 * 
 * @param tokens 
 * @return struct node* 
 */
struct node *parse(list *tokens);

/**
 * @brief Print a node
 * 
 */
void node_print(struct node *);

/**
 * @brief Print a node to file stream
 * 
 */
void node_fprint(FILE *, struct node *);

#endif
