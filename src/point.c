#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/point.h"

// exit codes
#define FAIL -1
#define SUCCESS 0

// create routine for memory
Point *point_create(int x, int y, int colour, const char *str)
{
    // handle invalid colour error
    if (colour < 1) return NULL;

    // handle NULL str error
    if (str == NULL) return NULL;

    // create pointer
    Point *point = malloc(sizeof(Point));

    // handle malloc error
    if (point == NULL) return NULL;

    // assign data
    point->x = x;
    point->y = y;
    point->colour = colour;
    point->str = strdup(str);

    // exit
    return point;
}

// create routine for memory
// I made this for number line, which isn't work yet
// review. I need to be able to print numbers
Point* point_create_int(int x, int y, int colour, int str)
{
    // create pointer
    Point *point = malloc(sizeof(Point));

    // handle malloc error
    if (point == NULL) return NULL;

    // assign data
    point->x = x;
    point->y = y;
    point->colour = colour;
    point->str = (char*) str;

    // exit
    return point;
}

// move current coordinate by amount
int point_move(Point *point, int x, int y)
{
    // handle NULL pointer error
    if (point == NULL) return FAIL;

    // assign data
    point->x += x;
    point->y += y;

    // exit
    return SUCCESS;
}

// move to coordinate (x, y)
int point_set(Point *point, int x, int y)
{
    // handle NULL pointer error
    if (point == NULL) return FAIL;

    // assign data
    point->x = x;
    point->y = y;

    // exit
    return SUCCESS;
}


// set colour to be printed
int point_set_colour(Point* point, int colour)
{
    // handle NULL pointer error
    if (point == NULL) return FAIL;

    // assign data
    point->colour = colour;

    //exit
    return SUCCESS;
}

// set string to be printed
int point_set_str(Point* point, const char* str)
{
    // handle NULL pointer error
    if (point == NULL) return FAIL;

    // handle NULL str error
    if(str == NULL) return FAIL;

    // assign data
    point->str = strdup(str);

    //exit
    return SUCCESS;
}

// draw on ncurses screen
int point_refresh(Point* point)
{
    // handle NULL pointer error
    if (point == NULL) return FAIL;

    // get maximums from screen size
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    // turn on colour
    attron(COLOR_PAIR(point->colour));

    // draw point on screen (translated to centre of screen for cartesian system)
    mvprintw((max_y / 2) - point->y, (max_x / 2) + (point->x * 2), "%s", point->str);

    // turn off colour
    attroff(COLOR_PAIR(point->colour));

    // exit
    return SUCCESS;
}

// create, refresh then destroy (drawn on the screen)
int point(int x, int y, int colour, const char *str)
{
    // handle invalid colour error
     if (colour < 1) return FAIL;

    // handle NULL str error
    if (str == NULL) return FAIL;

    // create pointer
    Point *point = point_create(x, y, colour, str);

    // handle malloc error
    if (point == NULL) return FAIL;

    // draw to screen
    point_refresh(point);

    // free memory
    free(point->str);
    free(point);
    point = NULL;

    // exit
    return SUCCESS;
}
