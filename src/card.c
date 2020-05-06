#include "../include/card.h"

card Card_hidden(void)
{
    card hiddencard;
    hiddencard.r = false;
    hiddencard.v = Ace;
    hiddencard.s = Spade;
    return hiddencard;
}

color Card_color(card * c)
{
    return c->s % 2;
}

void Card_hide(card * c)
{
    c->r = false;
}

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
