#include <curses.h>
#include "../include/consts.h"
#include "../include/gb.h"

static const char val_ch[3] =
{
    'J',
    'Q',
    'K'
};

static void printBackground(void)
{
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
    for(int y = 0; y < 100; y++)
    {
        for(int x = 0; x < 1000; x++)
        {
            mvprintw(y, x, " ");
        }
    }
    attroff(COLOR_PAIR(2));
    attron(COLOR_PAIR(1));
}

static void printCard(int y, int x, card * c)
{
#ifdef RANDOMSTRINGOFLETTERS
    if(!c->r) // If card is not revealed
    {
        printHiddenCard(y, x);
        return;
    }
#endif
    int color;
    if(Card_color(c) == black)
        color = 3;
    else /* if color is red */
        color = 2;

    // Apply color attributes
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(color));

    // Print white card background
    for(int yc = y; yc < y + 8; yc++)
    {
        for(int xc = x; xc < x + 10; xc++)
        {
            mvprintw(yc, xc, " ");
        }
    }

    // Print card suit symbol
#ifdef _MSVC_TRADITIONAL
    mvaddwstr(y, x, suit_ch[c->s]);
    mvaddwstr(y + 7, x + 9, suit_ch[c->s]);
#else
    mvprintw(y, x, "%s", suit_ch[c->s]);
    mvprintw(y + 7, x + 9, "%s", suit_ch[c->s]);
#endif
    // Print card value
    if(c->v == Ace)
    {
        mvprintw(y, x + 9, "A");
        mvprintw(y + 7, x, "A");
    }
    else if(c->v >= Two && c->v < Ten)
    {
        mvprintw(y, x + 9, "%i", c->v + 1);
        mvprintw(y + 7, x, "%i", c->v + 1);
    }
    else if(c->v == Ten)
    {
        mvprintw(y, x + 8, "10");
        mvprintw(y + 7, x, "10");
    }
    else if(c->v >= Jack)
    {
        mvprintw(y, x + 9, "%c", val_ch[c->v - Jack]);
        mvprintw(y + 7, x, "%c", val_ch[c->v - Jack]);
    }

    // Remove color attributes
    attroff(COLOR_PAIR(color));
    attron(COLOR_PAIR(1));
}

static void printHiddenCard(int y, int x)
{
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(4));
    for(int yc = y; yc < y + 7; yc++)
    {
        for(int xc = x; xc < x + 9; xc++)
        {
            mvprintw(yc, xc, " ");
        }
    }
    attron(COLOR_PAIR(1));
    attroff(COLOR_PAIR(4));
}

void printGB(Array * gb, Cursor * c)
{
    printBackground();
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
