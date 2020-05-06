#include <curses.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"
#include "../include/board.h"
#include "../include/card.h"
#include "../include/consts.h"
#include "../include/cursor.h"
#include "../include/gb.h"
#include "../include/suits.h"
#include "../include/values.h"

// Cyan is being redefined to gray in startcurses() so this macro is made to preserve readability
#define COLOR_GRAY COLOR_CYAN

// Gets user input
static int getinput(bool repeat);

// Frees gameboard
static void freearray(Array * a);

// Initializes array with 52 cards distributed on the gameboard
static void initarray(Array * a, card * deck);

// Adds 52 unique cards to deck
static void initcards(card * deck);

// Randomizes the order of the cards in deck
static void shufflecards(card * deck);

// Activates all attributes for the terminal using curses
static void startcurses(void);

int main(int argc, char * argv[])
{
    // User input
    int inp = '\0';

    // Create random seed from computer time
    srand(time(NULL));

    // Sets locale for printing unicode chars/strings
    setlocale(LC_ALL, "");

    // Applies predefined curses attributes
    startcurses();

    // Create 52 unique cards
    card cardobjs[52];
    initcards(cardobjs);

    // Randomize card arrangement
    shufflecards(cardobjs);

    // Initialize array of type Array with the discard, foundation, and tableau
    Array * board = (Array *) malloc(12 * sizeof(Array));
    initarray(board, cardobjs);
    refreshGB(board);

    // Initialize cursor
    Cursor cursor;
    Cursor_init(&cursor, 0, 0);

    do
    {
        printGB(board, &cursor);
        refresh();
        inp = getinput(false);
    } while(inp != 'e');

    // Free pointers and end ncurses window
    endwin();
    freearray(board);

    return 0;
}

static int getinput(bool repeat)
{
    int input;
    do
    {
        input = getch();
    } while(input == ERR && repeat);

    return input;
}

static void freearray(Array * a)
{
    for(int i = DS; i <= T7; i++)
    {
        Array_deallocate(&a[i]);
    }
    free(a);
}

static void initarray(Array * a, card * deck)
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

static void initcards(card * deck)
{
    for(int s = Spade, i = 0; s <= Heart; s++)
    {
        for(int v = Ace; v <= King; v++, i++)
        {
            Card_init(&deck[i], false, s, v);
        }
    }
}

static void shufflecards(card * deck)
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

static void startcurses(void)
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
    
    printw("Resize your terminal to 63x50 chars or more then press ENTER ");
    refresh();
    scanw("");

    // Check if colors can change
    if(can_change_color() == FALSE)
    {
        printw("Your terminal doesn't support changing of color attributes!\nIf you continue, the game may look weird. Is this fine? (y/N) ");
        refresh();
        char isfine;
        scanw("%c", &isfine);
        if(isfine != 'y' && isfine != 'Y')
        {
            endwin();
        	exit(1);
        }
    }
    
    init_color(COLOR_GRAY, 600, 600, 600);

    // Initializes color pairs
    init_pair(1, COLOR_GREEN, COLOR_GREEN); // Default green background
    init_pair(2, COLOR_RED, COLOR_WHITE);   // Red text on white background
    init_pair(3, COLOR_BLACK, COLOR_WHITE);  // Black text on white background
    init_pair(4, COLOR_BLUE, COLOR_BLUE); // Blue background for hidden cards
    init_pair(5, COLOR_RED, COLOR_YELLOW);   // Red text on yellow background
    init_pair(6, COLOR_BLACK, COLOR_YELLOW);  // Black text on yellow background
    init_pair(7, COLOR_RED, COLOR_GRAY);   // Red text on gray/cyan background
    init_pair(8, COLOR_BLACK, COLOR_GRAY);  // Black text on gray/cyan background


    // Apply default color mode and apply ncurses window attributes
    attron(COLOR_PAIR(1));
    raw();
    keypad(stdscr, true);
    noecho();
    halfdelay(1);
}
