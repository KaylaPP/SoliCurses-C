#ifndef ARRAY_H
#define ARRAY_H

#include "card.h"

typedef struct
{
    card * array;
    int used;
    int size;
} Array;

void Array_deallocate(Array * a);

void Array_expand(Array * a, int amount);

void Array_init(Array * a, int initAmount);

#endif