#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/point.h"
#include "../headers/cross.h"

// create routine for memory
Cross* cross_create(int x, int y, int colour)
{
    Cross* cross = malloc(sizeof(Cross));

    cross->x = x;
    cross->y = y;
    cross->colour = colour;

    return cross;
}

// destroy rountine for memory
void cross_destroy(Cross* cross)
{
    free(cross);
}

// move to coordinate (x, y)
void cross_set(Cross* cross, int x, int y)
{
    cross->x = x;
    cross->y = y;
}

void cross(int x, int y)
{
    #define CROSS_HORIZ_STR "#"
    #define CROSS_CENTRE_STR "X"

    //get maximums from screen size (it updates the vars)
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);

    //VERTICAL
    for(size_t i = 0; i < (size_t)max_y; i++)
    {
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

    //HORIZONTAL
    for(int i = 0; i < max_x; i++)
    {
        int num_to_print = abs((int)-i + (max_x/2)) / 2;

        
        if(i % 2 == 0)
        {
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
}

