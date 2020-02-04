#ifndef ARRAY_H
    #define ARRAY_H

#include "card.h"

typedef struct
{
    card ** array;
    int used;
    int size;
} Array;

// Deallocates a.array and sets a.used and a.size equal to 0
void Array_deallocate(Array * a);

// Increases size of array by amount
void Array_expand(Array * a, int amount);

// Constructor method for array which specifies an initial amount
void Array_init(Array * a, int initAmount);

#endif