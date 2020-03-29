#ifndef CURSOR_H
    #define CURSOR_H

typedef struct 
{
    int x;
    int y;
    int xmax;
    int ymax;
} Cursor;

void Cursor_init(Cursor * c);

#endif
