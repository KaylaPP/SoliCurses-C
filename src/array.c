#include <stdlib.h>
#include "../include/array.h"

void Array_append(Array * a, datatype element)
{
    if(a->used == a->size)
    {
        a->size++;
        a->used++;
        a->array = realloc(a->array, a->size * sizeof(datatype));
        a->array[a->size - 1] = element;
    }
    else
    {
        for(int i = a->size - 1; i >= 0; i--)
        {
            
        }
    }
    
}

void Array_deallocate(Array * a)
{
    free(a->array);
    a->used = 0;
    a->size = 0;
}

void Array_remove(Array * a, int index) 
{
    if(a->size == 1)
    {
        Array_deallocate(a);
        return;
    }
    for(int i = index; i < a->size - 1; i++)
    {
        a->array[i] = a->array[i + 1];
    }
    a->used--;
    a->size--;
    a->array = realloc(a->array, a->size * sizeof(datatype));
}

void Array_init(Array * a, int initAmount)
{
    a->array = malloc(initAmount * sizeof(datatype));
    a->used = 0;
    a->size = initAmount;
}
