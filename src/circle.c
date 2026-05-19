#include <ncurses.h>
#include <stdlib.h>

#include "../headers/point.h"
#include "../headers/circle.h"

//create routine in memory
Circle* circle_create(int x, int y, int radius, int colour, const char* str)
{
    Circle* circle = malloc(sizeof(Circle));
    circle->x = x;
    circle->y = y;
    circle->radius = radius;
    circle->colour = colour;
    circle->str = str;
    return circle;
}

//destory routine in memory
void circle_destroy(Circle* circle)
{
    free(circle);
}

#define M_PI 3.14159

//draw to ncurses screen
void circle_refresh(Circle* circle)
{
    attron(COLOR_PAIR(circle->colour));

    for(int i = circle->x - circle->radius; i < circle->x + circle->radius; i++)
    {
        for(int j = circle->y - circle->radius; j < circle->y + circle->radius; j++)
        {
            if((circle->x + i <  (2 * M_PI * circle->radius)))
            {
                Point* point = point_create(i, j, circle->colour, circle->str);
                point_refresh(point);
                point_destroy(point);
            }
        }
    }
    attroff(COLOR_PAIR(circle->colour));
}

//create, refresh then destroy (draw to screen)
    void circle(int x, int y, int radius, int colour, const char* str)
    {
    Circle* circle = circle_create(x, y, radius, colour, str);
    circle_refresh(circle);
    circle_destroy(circle);
}

