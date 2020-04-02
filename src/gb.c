#include <curses.h>
#include "../include/gb.h"

void printGB(Array * gb, cursor * c)
{

}

void refreshGB(Array * gb)
{
    for(int y = T1; y <= T7; y++)
    {
        Card_reveal(Array_last(&gb[y]));
    }
}
