#include <curses.h>
#include "../include/consts.h"
#include "../include/gb.h"

static void printBackground()
{
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    for(int y = 0; y < 1; y++)
    {
        for(int x = 0; x < 1; x++)
        {
            break;
        }
    }
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
}

static void printCard(int y, int x, card * c)
{
    int color;
    if(Card_color(c) == black)
        color = 3;
    else /* if color is red */
        color = 2;

    // Apply color attributes
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(color));

    // Print white background
    for(int yc = y; yc < y + 8; yc++)
    {
        for(int xc = x; xc < x + 10; xc++)
        {
            mvprintw(yc, xc, " ");
        }
    }

    // Print card suit symbol and card value
#ifdef _MSVC_TRADITIONAL
    mvaddwstr(y, x, suit_ch[c->s]);
    if(c->v < 10)
        mvprintw(y, x + 9, "%i", c->v);
    else
        mvprintw(y, x + 8, "%i", c->v);
    mvaddwstr(y + 7, x + 9, suit_ch[c->s]);
    mvprintw(y + 7, x, "%i", c->v);
#else
    mvprintw(y, x, "%s", suit_ch[c->s]);
    mvprintw(y, x + 9, "%i", c->v);
    mvprintw(y + 7, x + 9, "%s", suit_ch[c->s]);
    mvprintw(y + 7, x, "%i", c->v);
#endif

    // Remove color attributes
    attroff(COLOR_PAIR(color));
    attron(COLOR_PAIR(1));
}

void printGB(Array * gb, Cursor * c)
{
    printCard(2, 4, gb[0].array[0]);
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
