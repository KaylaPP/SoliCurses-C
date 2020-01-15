#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../include/array.h"
#include "../include/card.h"
#include "../include/suits.h"

int main(void)
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
    
    // Initializes the 4 different color modes
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default white text on black background
    init_pair(2, COLOR_RED, COLOR_BLACK);   // Used for printing red cards
    init_pair(3, COLOR_BLACK, COLOR_WHITE); // Selected white card
    init_pair(4, COLOR_WHITE, COLOR_RED);   // Selected red card

    attron(COLOR_PAIR(1));
    raw();
    keypad(stdscr, true);
    noecho();
    halfdelay(1);

    endwin();

    card oop;
    oop.s = Heart;

    Array var;
    Array_init(&var, 1);
    Array_append(&var, oop);

    printf("%i", var.array[0].s);

    return 0;
}