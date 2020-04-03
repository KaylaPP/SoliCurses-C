#include <curses.h>
#include "../include/gb.h"

static void printCard(card c)
{

}

void printGB(Array * gb, cursor * c)
{
    
}

void refreshGB(Array * gb)
{
    // Flip last cards in tableau face up
    for(int y = T1; y <= T7; y++)
    {
        Card_reveal(Array_last(&gb[y]));
    }

    // Leaves all cards in foundation except the last flipped face up
    for(int y = F1; y <= F4; y++)
    {
        for(int x = 0; x < gb[y].used; x++)
        {
            Card_hide(gb[y].array[x]);
        }
        Card_reveal(Array_last(&gb[y]));
    }
}
