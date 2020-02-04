#define SOLICURSES_DEBUG

#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"
#include "../include/card.h"
#include "../include/suits.h"
#include "../include/values.h"

void debugdeck(card * deck);

void initcards(card * deck);

void shufflecards(card * deck);

void startcurses(void);

int main(void)
{
    // Create random seed from machine time
    srand(time(NULL));

    // Initialize ncurses attributes
    startcurses();

    // Create 52 unique cards and a placholder
    card cardobjs[52];
    card PH;
    
    Card_init(&PH, true, S_PH, V_PH);
    initcards(cardobjs);

    // Randomize card arrangement
    shufflecards(cardobjs);

    // Free pointers and end ncurses window
    endwin();

    return 0;
}

void debugdeck(card * deck)
{
#ifdef SOLICURSES_DEBUG
    for(int i = 0; i < 52; i++)
    {
        printf("%i %i %i\n", deck[i].s, deck[i].v, deck[i].r);
    }
#endif
}

void initcards(card * deck)
{
    for(int s = 1, i = 0; s <= 4; s++)
    {
        for(int v = 1; v <= 13; v++, i++)
        {
            Card_init(&deck[i], false, s, v);
        }
    }
}

void shufflecards(card * deck)
{
    for(int i = 0; i < 52; i++)
    {
        int rand_1 = rand() % 52;
        int rand_2 = rand() % 52;

        card temp = deck[rand_1];
        deck[rand_1] = deck[rand_2];
        deck[rand_2] = temp;
    }
}

void startcurses(void)
{
    // Initialize ncurses terminal mode
    initscr();
    if(has_colors() == FALSE)
    {    
        endwin();
        printf("Your terminal doesn't support color!");
        exit(1);
    }
    start_color();
    
    // Initializes colors
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default white text on black background

    // Apply default color mode and apply ncurses window attributes
    attron(COLOR_PAIR(1));
    raw();
    keypad(stdscr, true);
    noecho();
    halfdelay(1);
}
