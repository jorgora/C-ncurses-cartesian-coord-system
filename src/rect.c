#include <ncurses.h>
#include <stdlib.h>

#include "../headers/rect.h"
#include "../headers/point.h"

//create routine in memory
Rect* rect_create(int x, int y, int width, int height, int colour, const char* str)
{
    Rect* rect = malloc(sizeof(Rect));
    rect->x = x;
    rect->y = y;
    rect->width = width;
    rect->height = height;
    rect->colour = colour;
    rect->str = str;
    return rect;
}

//destroy routine in memory
void rect_destroy(Rect* rect)
{
    free(rect);    
}

//draw to ncurses screen
void rect_refresh(Rect* rect)
{
    attron(COLOR_PAIR(rect->colour));

    for(int i = rect->x; i < (rect->x + rect->width + 1); i++)
    {
        for(int j = rect->y; j < (rect->y + rect->height + 1); j++)
        {
            Point* point = point_create(i, j, rect->colour, rect->str);
            point_refresh(point);
            point_destroy(point);
        }
    }

    attroff(COLOR_PAIR(rect->colour));
}

// create, refresh then destroy, drawn on screen
void rect(int x, int y, int width, int height, int colour, const char* str)
{
    Rect* rect = rect_create(x, y, width, height, colour, str);
    rect_refresh(rect);
    rect_destroy(rect);
}



