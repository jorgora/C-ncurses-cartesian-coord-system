#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/point.h"
#include "../headers/cross.h"

// exit codes
#define FAIL -1
#define SUCCESS 0

// create routine for memory
Cross* cross_create(int x, int y, int colour)
{
    // handle invalid colour error
    if (colour < 1) return NULL;

    // create pointer
    Cross* cross = malloc(sizeof(Cross));

    // handle malloc error
    if (cross == NULL) return NULL;

    //assign data
    cross->x = x;
    cross->y = y;
    cross->colour = colour;

    // exit
    return cross;
}

// move to coordinate (x, y)
int cross_set(Cross* cross, int x, int y)
{
    // handle NULL pointer error
    if (cross == NULL) return FAIL;

   // assign data 
    cross->x = x;
    cross->y = y;

    //exit
    return SUCCESS;
}

// create, refresh then destroy (drawn on the screen)
int cross(int x, int y)
{
    #define CROSS_HORIZ_STR "#"
    #define CROSS_CENTRE_STR "X"

    //get maximums from screen size (it updates the vars)
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    // VERTICAL
    // for each Y 
    for(size_t i = 0; i < (size_t)max_y; i++)
    {
        // calculate cartesian Y grid number
        int num_to_print = abs((int)-i + (max_y/2));
        
        //if 10 or greater, move 1 to the left so matches up 
        if(num_to_print < 10)
        {
            mvprintw(i, (max_x / 2) + (x * 2),  "%d", num_to_print);
        }
        else
        {
            mvprintw(i, (max_x / 2) + (x * 2)-1,  "%d", num_to_print);            
        }
    }

    // HORIZONTAL
    // for each X
    for(int i = 0; i < max_x; i++)
    {
        // calculate cartesian Y grid number
        int num_to_print = abs((int)-i + (max_x/2)) / 2;

        // if X is equal
        if(i % 2 == 0)
        {
            // if grid number is less than 10
            if(num_to_print < 10)
            {
                mvprintw((max_y / 2) - y, i, "%d", num_to_print);
            }
            else
            { 
                mvprintw((max_y / 2) - y, i, "%d", num_to_print);
                mvprintw((max_y / 2) - y+1, i, "%d", num_to_print % 10);
            }
        }
        else
        {
            mvprintw((max_y / 2) - y, i, "~");      
        }
        
    }

    mvprintw((max_y / 2) - y, (max_x / 2) + (x*2), "0");

    // exit
    return SUCCESS;
}

