#include <stdlib.h>
#include "../include/array.h"

void Array_deallocate(Array * a)
{
    free(a->array);
    a->used = 0;
    a->size = 0;
}

void Array_expand(Array * a, int amount)
{
    a->array = realloc(a->array, (a->size + amount) * sizeof(DATATYPE));
}

void Array_init(Array * a, int initAmount)
{
    a->array = malloc(initAmount * sizeof(DATATYPE));
    a->used = 0;
    a->size = initAmount;
}
