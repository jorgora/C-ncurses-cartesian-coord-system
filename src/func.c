#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/func.h"
#include "../headers/point.h"

// create routine in memory
Func* func_create(double (*func) (double x), int colour, const char* str)
{
    Func* function = malloc(sizeof(Func));
    function->func = func;
    function->colour = colour;
    function->str = str;
}

// destroy routine in memory
void func_destroy(Func* func)
{
    free(func);
}

// draw on ncurse screen
void func_refresh(Func* func)
{
    // get maximums from screen size
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);
    

    for(int i = -100; i < max_x; i++)
    { 
        point(i, floor(func->func(i)), func->colour, func->str);   
    }
}

// set colour of func
void func_set_colour(Func* func, int colour)
{
    func->colour = colour;
}

// set string of func
void func_set_str(Func* func, const char* str)
{
    func->str = str;
}

// create, refresh then destroy the point, leaving it drawn on the screen
void func(double (*func) (double x), int colour, const char* str)
{
    Func* function = func_create(func, colour, str);
    func_refresh(function);
    func_destroy(function);
}
