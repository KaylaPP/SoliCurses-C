#pragma once

typedef struct 
{
    int x;
    int y;
    int xmax;
    int ymax;
} Cursor;

void Cursor_init(Cursor * c);
