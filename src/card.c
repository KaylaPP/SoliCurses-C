#include "../include/card.h"

void Card_init(card * c, bool revealed, suit newsuit, value newvalue)
{
    c->s = newsuit;
    c->v = newvalue;
    c->r = revealed;
}

void Card_reveal(card * c)
{
    c->r = true;
}