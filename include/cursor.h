#pragma once

#include "direction.h"

// Cursors with a range of [0, xmax] or [0, ymax] [inclusive]
typedef struct 
{
    int y;
    int x;
    int ymax;
    int xmax;
} cursor;

// Initialize cursor
void Cursor_init(cursor * c, int ym, int xm);

// Move cursor in a specific direction
void Cursor_move(cursor * c, direction d);
