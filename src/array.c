#include <stdlib.h>
#include "../include/array.h"

void Array_append(Array * a, card element)
{
    if(a->used == a->size)
    {
        
    }
}

//void Array_deallocate(Array * a);

//void Array_delete(Array * a, int index);

void Array_init(Array * a, int initAmount)
{
    a->array = malloc(initAmount * sizeof(card));
    a->used = 0;
    a->size = initAmount;
}
