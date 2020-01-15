#ifndef CARD_H
# define CARD_H

#include <stdbool.h>
#include "suits.h"
#include "values.h"

typedef struct
{
    bool r; // Card revealed or not
    suit s; // Suit of card
    value v;// Value of card
} card;

void Card_init(card * c, bool revealed, suit newsuit, value newvalue);

#endif
