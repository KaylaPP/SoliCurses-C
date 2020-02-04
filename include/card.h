#ifndef CARD_H
#define CARD_H

#include <stdbool.h>
#include "suits.h"
#include "values.h"

typedef struct
{
    bool r; // Card revealed or not
    suit s; // Suit of card
    value v;// Value of card
} card;

// Constructor method for a card
void Card_init(card * c, bool revealed, suit newsuit, value newvalue);

// Reveals a card irreversibly by setting c.r equal to true
void Card_reveal(card * c);

#endif
