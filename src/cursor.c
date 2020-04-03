#include "../include/cursor.h"
#include "../include/direction.h"

void Cursor_init(cursor * c, int ym, int xm)
{
    c->ymax = ym;
    c->xmax = xm;
}

void Cursor_move(cursor * c, direction d)
{
    switch(d)
    {
    case up:
        c->y--;
        if(c->y < 0)
            c->y = 0;
        break;
    case down:
        c->y++;
        if(c->y > c->ymax)
            c->y = c->ymax;
        break;
    case left:
        c->x--;
        if(c->x < 0)
            c->x = 0;
        break;
    case right:
        c->x++;
        if(c->x > c->xmax)
            c->x = c->xmax;
        break;
    default:
        break;
    }
}
