#include <ncurses.h>
#include <stdlib.h>

#include "../headers/numberline.h"
#include "../headers/point.h"

//create routine in memory
Numberline* numberline_create(int x, int y, int length, int colour)
{
    Numberline* numberline = malloc(sizeof(Numberline));
    numberline->x = x;
    numberline->y = y;
    numberline->length = length;
    numberline->colour= colour;
    return numberline;
}

//destroy routine in memory
void numberline_destroy(Numberline* numberline)
{
    free(numberline);    
}

//draw to ncurses screen
void numberline_refresh(Numberline* numberline)
{
    attron(COLOR_PAIR(numberline->colour));


    int counter = 0;
    
    for(int i = numberline->x; i < (numberline->x + numberline->length + 1); i++)
    {
        Point* point = point_create(numberline->x + i, numberline->y, numberline->colour, "0-");
        point_refresh(point);
        point_destroy(point);
        counter++;
    }

    attroff(COLOR_PAIR(numberline->colour));
}

// create, refresh then destroy, drawn on screen
void numberline(int x, int y, int length, int colour)
{
    Numberline* numberline = numberline_create(x, y, length, colour);
    numberline_refresh(numberline);
    numberline_destroy(numberline);
}





