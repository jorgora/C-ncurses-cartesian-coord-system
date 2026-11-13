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

//draw to ncurses screen
void numberline_refresh(Numberline* numberline)
{
    //int counter = 0;
    
    for(int i = numberline->x; i < (numberline->x + numberline->length + 1); i++)
    {
        point(numberline->x + i, numberline->y, numberline->colour, "0-");
        //counter++;
    }
}

// create, refresh then destroy, drawn on screen
void numberline(int x, int y, int length, int colour)
{
    // create pointer
    Numberline *numberline = numberline_create(x, y, length, colour);

    // draw to screen
    numberline_refresh(numberline);

    // destroy pointer
    free(numberline);
    numberline = NULL;
}





