#include <stdlib.h>
#include "../include/array.h"

card * Array_last(Array * a)
{
    return a->array[a->used - 1];
}

void Array_append(Array * a, card * c)
{
    if(a->used == a->size) // If all indices of a->array are full
    {
        a = realloc(a, (a->size + 1) * sizeof(card *));
        a->size++;
        a->array[a->size - 1] = c;
        a->used++;
    }
    else
    {
        a->array[a->used - 1] = c;
        a->used++;
    }
}

void Array_deallocate(Array * a)
{
    free(a->array);
    a->used = 0;
    a->size = 0;
}

void Array_init(Array * a)
{
    a->array = malloc(sizeof(card *));
    a->used = 0;
    a->size = 1;
}
