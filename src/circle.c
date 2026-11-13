#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../headers/point.h"
#include "../headers/circle.h"

// exit codes
 #define FAIL -1
#define SUCCESS 0

//create routine in memory
Circle* circle_create(int x, int y, int radius, int colour, const char* str)
{
    // handle invalid colour error
    if(colour < 1) return NULL;

    // handle NULL str error
    if(str == NULL) return NULL;

    // create pointer
    Circle* circle = malloc(sizeof(Circle));
    
    // handle malloc error 
    if(circle== NULL) return NULL;

    // assign data 
    circle->x = x;
    circle->y = y;
    circle->radius = radius;
    circle->colour = colour;
    circle->str = strdup(str);

    // exit
    return circle;
}

//draw to ncurses screen
int circle_refresh(Circle* circle)
{
    // handle NULL pointer error
    if (circle == NULL) return FAIL;

    // draw function
    for(int i = circle->x - circle->radius; i < circle->x + circle->radius; i++)
    {
        for(int j = circle->y - circle->radius; j < circle->y + circle->radius; j++)
        {
            if((circle->x + i <  (2 * M_PI * circle->radius)))
            {
                Point* point = point_create(i, j, circle->colour, circle->str);
                point_refresh(point);
                free(point);
                point = NULL;
            }
        }
    }

    // exit
    return SUCCESS;
}

//create, refresh then destroy (draw to screen)
int circle(int x, int y, int radius, int colour, const char *str)
{
    // handle invalid colour error
     if (colour < 1) return FAIL;

    // handle NULL str error
    if (str == NULL) return FAIL;
    
    // create pointer
    Circle *circle = circle_create(x, y, radius, colour, str);

    // handle malloc error
    if (circle == NULL) return FAIL;

    // draw to screen
    circle_refresh(circle);

    // free memory
    free(circle->str);
    free(circle);
    circle = NULL;

    // exit
    return SUCCESS;
}

