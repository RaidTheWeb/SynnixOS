#ifndef HERMES_DATA_TYPE_H
#define HERMES_DATA_TYPE_H

#define DATA_TYPE_MODIFIER_LONG 1

typedef struct DATA_TYPE_STRUCT
{
    enum
    {
        DATA_TYPE_VOID,
        DATA_TYPE_STRING,
        DATA_TYPE_CHAR,
        DATA_TYPE_INT,
        DATA_TYPE_FLOAT,
        DATA_TYPE_BOOLEAN,
        DATA_TYPE_OBJECT,
        DATA_TYPE_ENUM,
        DATA_TYPE_LIST,
        DATA_TYPE_SOURCE
    } type;

    int modifiers[3];
} data_type_T;

data_type_T* init_data_type();

data_type_T* init_data_type_as(int type);

data_type_T* data_type_copy();

unsigned int data_type_has_modifier(data_type_T* data_type, int modifier);
#endif
