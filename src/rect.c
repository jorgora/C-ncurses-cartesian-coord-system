#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/point.h"
#include "../headers/rect.h"

#define FAIL -1
#define SUCCESS 0

// create routine for memory
Rect *rect_create(int x, int y, int width, int height, int colour, const char *str)
{
   // handle invalid colour error
    if (colour < 1) return NULL;

    // handle NULL str error
    if (str == NULL) return NULL;

    // create pointer
    Rect *rect = malloc(sizeof(Rect));

    // handle malloc error
    if (rect == NULL) return NULL;

    // assign data
    rect->x = x;
    rect->y = y;
    rect->width = width;
    rect->height = height;
    rect->colour = colour;
    rect->str = strdup(str);

    //exit
    return rect;
}

// set colour to be printed
int rect_set_colour(Rect* rect, int colour)
{
    // handle NULL pointer error
    if (rect == NULL) return FAIL;

    //assign data
    rect->colour = colour;

    //exit
    return SUCCESS;
}

// set string to be printed
int rect_set_str(Rect *rect, const char *str)
{
    // handle NULL pointer error
    if (rect == NULL) return FAIL;

    // handle NULL str error
    if(str == NULL) return FAIL;

    // assign data
    rect->str = strdup(str);

    //exit
    return SUCCESS;
}

// draw to ncurses screen
int rect_refresh(Rect *rect)
{
    // handle NULL pointer error
    if (rect == NULL) return FAIL;

    // draw to screen
    attron(COLOR_PAIR(rect->colour));
    for(int i = rect->x; i < (rect->x + rect->width + 1); i++)
    {
        for(int j = rect->y; j < (rect->y + rect->height + 1); j++)
        {
            point(i, j, rect->colour, rect->str);
        }
    }
    attroff(COLOR_PAIR(rect->colour));

    //exit
    return SUCCESS;
}

// create, refresh then destroy (drawn on screen)
int rect(int x, int y, int width, int height, int colour, const char *str)
{
   // handle invalid colour error
    if (colour < 1) return FAIL;

    // handle NULL str error
    if (str == NULL) return FAIL;

    // create pointer
    Rect *rect = rect_create(x, y, width, height, colour, str);

    // handle malloc error
    if (rect == NULL) return FAIL;

    // draw to screen
    rect_refresh(rect);

    // free memory
    free(rect->str);
    free(rect);
    rect = NULL;

    // exit
    return SUCCESS;
}
