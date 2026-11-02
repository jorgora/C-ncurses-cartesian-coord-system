#include <ncurses.h>
#include <stdlib.h>

#include "../headers/point.h"

// create routine for memory
Point *point_create(int x, int y, int colour, const char *str)
{
    // create pointer
    Point *point = malloc(sizeof(Point));

    // handle error
    if (point == NULL)
    {
        return NULL;
    }

    // assign data
    point->x = x;
    point->y = y;
    point->colour = colour;
    point->str = str;

    return point;
}

// create routine for memory
// I made this for number line, which isn't work yet
// review. I need to be able to print numbers
Point* point_create_int(int x, int y, int colour, int str)
{
    // create pointer
    Point *point = malloc(sizeof(Point));

    // handle error
    if (point == NULL)
    {
        return NULL;
    }

    // assign data
    point->x = x;
    point->y = y;
    point->colour = colour;
    point->str = (const char *)str;

    return point;
}

// move current coordinate by amount
int point_move(Point *point, int x, int y)
{
    // handle error
    if (point == NULL)
    {
      return EXIT_FAILURE;
    }

    // assign data
    point->x += x;
    point->y += y;

    return EXIT_SUCCESS;
}

// move to coordinate (x, y)
int point_set(Point *point, int x, int y)
{
    // handle error
    if (point == NULL)
    {
      return EXIT_FAILURE;
    }

    // assign data
    point->x = x;
    point->y = y;

    return EXIT_SUCCESS;
}

// draw on ncurses screen
int point_refresh(Point* point)
{
    // handle error
    if (point == NULL)
    {
      return EXIT_FAILURE;
    }

    // get maximums from screen size
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    // draw point
    attron(COLOR_PAIR(point->colour));
    mvprintw((max_y / 2) - point->y, (max_x / 2) + (point->x * 2), "%s", point->str);
    attroff(COLOR_PAIR(point->colour));

    return EXIT_SUCCESS;
}

// set colour to be printed
int point_set_colour(Point* point, int colour)
{
    // handle error
    if (point == NULL)
    {
      return EXIT_FAILURE;
    }

    // assign data
    point->colour = colour;

    return EXIT_SUCCESS;
}

// set string to be printed
int point_set_str(Point* point, const char* str)
{
    // handle error
    if (point == NULL)
    {
      return EXIT_FAILURE;
    }

    // assign data
    point->str = str;
    return EXIT_SUCCESS;
}

// create, refresh then destroy (drawn on the screen)
int point(int x, int y, int colour, const char *str)
{
    // create pointer
    Point *point = point_create(x, y, colour, str);

    // handle error
    if (point == NULL)
    {
        return EXIT_FAILURE;
    }

    // draw to screen
    point_refresh(point);

    // free memory
    free(point);
    point = NULL;

    // return
    return EXIT_SUCCESS;
}
