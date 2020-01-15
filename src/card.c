#include "../include/card.h"

void Card_init(card * c, bool revealed, suit newsuit, value newvalue)
{
    c->s = newsuit;
    c->v = newvalue;
    c->r = revealed;
}