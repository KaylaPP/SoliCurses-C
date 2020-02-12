#define SOLICURSES_DEBUG

#include <curses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"
#include "../include/board.h"
#include "../include/card.h"
#include "../include/suits.h"
#include "../include/values.h"

// Prints out each attribute of every card in deck
void debugdeck(card * deck);

// Initializes array with 52 cards distributed on the gameboards
void initarray(Array * a, card * deck);

// Adds 52 unique cards to deck
void initcards(card * deck);

// Randomizes the order of the cards in deck
void shufflecards(card * deck);

// Activates all attributes for the terminal using ncurses
void startcurses(void);

int main(void)
{
    // Create random seed from computer time
    srand(time(NULL));

    startcurses();

    // Create 52 unique cards and a placholder
    card * cardobjs = (card *) malloc(52 * sizeof(card));
    initcards(cardobjs);

    // Randomize card arrangement
    shufflecards(cardobjs);

    // Initialize array of type Array with the discard, foundation, and tableau
    Array * board;
    board = (Array *) malloc(12 * sizeof(Array));
    initarray(board, cardobjs);

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

void initarray(Array * a, card * deck)
{
    int count = 0;

    for(int i = DS; i <= T7; i++)
    {
        Array_init(&a[i], 1);
    }

    for(int i = T1; i <= T7; i++)
    {
        for(int j = 0; j <= i - T1; j++)
        {
            Array_append(&a[i], &deck[count++]);
        }
    }
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
    // Initialize curses terminal attributes
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
