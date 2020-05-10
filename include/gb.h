#pragma once

#include "array.h"
#include "board.h"
#include "card.h"
#include "color.h"
#include "cursor.h"

typedef struct
{
    Array * gb;
    bool gamestart;
    bool gamestop;
    bool gamewin;
    time_t starttime;
    time_t endttime;
} GB;

// Initializes GB with 52 cards distributed on the gameboard
void initGB(GB * gb, card * deck);

void doinput(GB * gb, Cursor * c, int input);

void printGB(GB * gb, Cursor * c);

void refreshGB(GB * gb);
