#pragma once

#include <stdbool.h>
#include "color.h"
#include "suits.h"
#include "values.h"

typedef struct
{
    bool r;  // Card revealed or not
    suit s;  // Suit of card
    value v; // Value of card
} card;

color Card_color(card * c);

// Hides a card by setting c->r to false
void Card_hide(card * c);

// Constructor method for a card
void Card_init(card * c, bool revealed, suit newsuit, value newvalue);

// Reveals a card by setting c->r to true
void Card_reveal(card * c);
