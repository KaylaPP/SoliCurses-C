#include <stdlib.h>
#include "../include/array.h"

card * Array_last(Array * a)
{
    return a->array[a->used - 1];
}

void Array_append(Array * a, card * c) {
    if (a->used == a->size) 
    {
        a->size *= 2;
        a->array = (card **) realloc(a->array, a->size * sizeof(card *));
    }
    a->array[a->used++] = c;
}

void Array_deallocate(Array * a)
{
    free(a->array);
    a->used = 0;
    a->size = 0;
}

void Array_init(Array * a)
{
    a->array = (card **) malloc(sizeof(card *));
    a->used = 0;
    a->size = 1;
}
