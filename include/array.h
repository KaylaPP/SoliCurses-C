#ifndef ARRAY_H
# define ARRAY_H

#include "card.h"

typedef struct
{
    card * array;
    int used;
    int size;
} Array;

void Array_append(Array * a, card element);

void Array_deallocate(Array * a);

void Array_init(Array * a, int initAmount);

void Array_remove(Array * a, int index);

#endif