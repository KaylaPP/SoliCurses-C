#include <ncurses.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../include/array.h"
#include "../include/card.h"
#include "../include/suits.h"
#include "../include/values.h"



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
    
    // Initializes colors
    init_pair(1, COLOR_WHITE, COLOR_BLACK); // Default white text on black background

    // Apply default color mode and apply ncurses window attributes
    attron(COLOR_PAIR(1));
    raw();
    keypad(stdscr, true);
    noecho();
    halfdelay(1);

    // Create 52 unique cards
    card cardobjs[52];
    for(int s = 0, i = 0; s < 4; s++)
    {
        for(int v = 0; v < 13; v++, i++)
        {
            cardobjs[i].s = s;
            cardobjs[i].v = v;
            cardobjs[i].r = false;
        }
    }

    // Free pointers and end ncurses window
    endwin();

    return 0;
}
