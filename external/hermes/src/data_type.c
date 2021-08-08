#include "include/data_type.h"
#include <stdlib.h>


data_type_T* init_data_type()
{
    data_type_T* data_type = calloc(1, sizeof(struct DATA_TYPE_STRUCT));
    data_type->type = 0;
    data_type->modifiers[0] = 0;
    data_type->modifiers[1] = 0;
    data_type->modifiers[2] = 0;

    return data_type;
}

data_type_T* init_data_type_as(int type)
{
    data_type_T* data_type = init_data_type();
    data_type->type = type;

    return data_type;
}

data_type_T* data_type_copy(data_type_T* src)
{
    data_type_T* data_type = init_data_type();
    data_type->type = src->type;
    data_type->modifiers[0] = src->modifiers[0];
    data_type->modifiers[1] = src->modifiers[1];
    data_type->modifiers[2] = src->modifiers[2];

    return data_type;
}

unsigned int data_type_has_modifier(data_type_T* data_type, int modifier)
{
    if (data_type == (void*)0)
        return 0;

    for (int i = 0; i < 2; i++)
        if (data_type->modifiers[i] == modifier)
            return 1;

    return 0;
}
