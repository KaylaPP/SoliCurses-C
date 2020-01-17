#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"
#include "../include/card.h"
#include "../include/suits.h"
#include "../include/values.h"

void make_and_shuffle(card ** deck)
{
    deck = malloc(52 * sizeof(card));
    for(int newsuit = 1, count = 0; newsuit <= 4; newsuit++)
    {
        for(int newval = 1; newval <= 13; newval++, count++)
        {
            deck[count] = malloc(sizeof(card));
            Card_init(deck[count], false, (suit) newsuit, (value) newval);
        }
    }
}

void delete_cards(card ** deck)
{
    for(int i = 0; i < 52; i++)
    {
        free(deck[i]);
    }
}

int main(void)
{
    // Create random seed from machine time
    srand(time(NULL));

    // Initialize ncurses terminal mode
    initscr();
    if(has_colors() == FALSE)
    {    
        endwin();
        printf("Your terminal doesn't support color!");
        exit(1);
    }
    start_color();
    
    // Initializes the 4 different color modes
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default white text on black background

    // Apply default color mode and set terminal attributes
    attron(COLOR_PAIR(1));
    raw();
    keypad(stdscr, true);
    noecho();
    halfdelay(1);

    // Create and shuffle cards
    //Array deck;
    //Array_init(&deck, 52);
    //make_and_shuffle(deck.array);

    // Create placeholder card
    //card * PH;
    //Card_init(PH, true, S_PH, V_PH);

    // Free pointers and remove terminal attributes
    //delete_cards(deck.array);
    //Array_deallocate(&deck);
    endwin();

    for(int i = 0; i < 256; i++)
    {
        printf("%c", i);
    }
    printf("\n");
    return 0;
}