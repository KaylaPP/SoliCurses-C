#define SOLICURSES_DEBUG

#include <curses.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"
#include "../include/board.h"
#include "../include/card.h"
#include "../include/suits.h"
#include "../include/values.h"

// The unicode characters for card suits in UTF-8 encoding
static const char suit_ch[4][4] =
{
    {0xE2, 0x99, 0xA0, '\0'}, // Spade
    {0xE2, 0x99, 0xA3, '\0'}, // Club
    {0xE2, 0x99, 0xA6, '\0'}, // Diamond
    {0xE2, 0x99, 0xA5, '\0'}  // Heart
};

// Prints gameboard in a grid with all attributes visible
void debugarray(Array * a);

// Prints out each attribute of every card in deck
void debugdeck(card * deck);

// Frees gameboard
void freearray(Array * a);

// Initializes array with 52 cards distributed on the gameboard
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

    // Sets locale for printing unicode chars/strings
    setlocale(LC_ALL, "");

    // Applies predefined ncurses attributes
    startcurses();

    // Create 52 unique cards and a placholder
    card cardobjs[52];
    initcards(cardobjs);

    // Randomize card arrangement
    shufflecards(cardobjs);

    // Initialize array of type Array with the discard, foundation, and tableau
    Array * board = (Array *) malloc(12 * sizeof(Array));
    initarray(board, cardobjs);
    Array_recursive_remove(&board[T4], -1);
    debugarray(board);
    refresh();

    // Free pointers and end ncurses window
    char input;
    do
    {
        input = getch();
    } while (input == ERR);

    endwin();
    freearray(board);

    return 0;
}

void debugarray(Array * a)
{
#ifdef SOLICURSES_DEBUG
    for(int i = DS; i <= T7; i++)
    {
        for(int j = 0; j < a[i].used; j++)
        {
            // FUTURE: mvprintw without tabs
            printw("%is%s\t%iv\t%ir|\t", a[i].array[j]->s, suit_ch[a[i].array[j]->s], a[i].array[j]->v, a[i].array[j]->r);
        }
        printw("\n");
    }
#endif
}

void debugdeck(card * deck)
{
#ifdef SOLICURSES_DEBUG
    for(int i = 0; i < 52; i++)
    {
        printw("%i %i %i\n", deck[i].s, deck[i].v, deck[i].r);
    }
#endif
}

void freearray(Array * a)
{
    for(int i = DS; i <= T7; i++)
    {
        Array_deallocate(&a[i]);
    }
    free(a);
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
        Card_reveal(Array_last(&a[i]));
    }

    while(count < 52)
    {
        Array_append(&a[DS], &deck[count++]);
    }
}

void initcards(card * deck)
{
    for(int s = Spade, i = 0; s <= Heart; s++)
    {
        for(int v = Ace; v <= King; v++, i++)
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
