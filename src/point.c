#include <ncurses.h>
#include <stdlib.h>

#include "../headers/point.h"

// create routine in memory
Point* point_create(int x, int y, int colour, const char* str)
{
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    point->colour = colour;
    point->str = str;
    return point;
}

// create routine for memory
// I made this for number line, which doesn't work
Point* point_create_int(int x, int y, int colour, int str)
{
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    point->colour = colour;
    point->str = (const char*) str;
    return point;
}

// destroy routine for memory
void point_destroy(Point* point)
{
    free(point); 
}

// move current coordinate by amount
void point_move(Point* point, int x, int y)
{
    point->x += x;
    point->y += y;
}

// move to coordinate (x, y)
void point_set(Point* point, int x, int y)
{
    point->x = x;
    point->y = y;
}

// draw on ncurses screen
void point_refresh(Point* point)
{
    // get maximums from screen size
    size_t max_y = 0;
    size_t max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    // draw point
    attron(COLOR_PAIR(point->colour));
    mvprintw((max_y / 2) - point->y, (max_x / 2) + (point->x * 2), "%s", point->str);
    attroff(COLOR_PAIR(point->colour));
}

// set colour of point
void point_set_colour(Point* point, int colour)
{
    point->colour = colour;
}

// set string of point
void point_set_str(Point* point, const char* str)
{
    point->str = str;
}

// create, refresh then destroy the point, leaving it drawn on the screen
void point(int x, int y, int colour, const char* str)
{
    Point* point = point_create(x, y, colour, str);
    point_refresh(point);
    point_destroy(point);
}

