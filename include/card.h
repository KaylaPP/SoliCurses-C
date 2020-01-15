#ifndef CARD_H
# define CARD_H

#include <stdbool.h>
#include "suits.h"
#include "values.h"

typedef struct
{
    bool r;
    suit s;
    value v;
} card;

#endif