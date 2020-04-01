#pragma once

#include <curses.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "board.h"
#include "card.h"
#include "consts.h"
#include "gb.h"
#include "suits.h"
#include "values.h"

// Prints gameboard in a grid with all attributes visible
void debugarray(Array* a);

// Frees gameboard
void freearray(Array* a);

// Initializes array with 52 cards distributed on the gameboard
void initarray(Array* a, card* deck);

// Adds 52 unique cards to deck
void initcards(card* deck);

// Randomizes the order of the cards in deck
void shufflecards(card* deck);

// Activates all attributes for the terminal using ncurses
void startcurses(void);
