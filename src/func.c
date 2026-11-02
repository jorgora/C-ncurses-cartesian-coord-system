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

    return function;
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

// set function pointer of func to be printed
void func_set_func(Func* func, double (*function) (double x))
{
    func->func = function;
}

// set colour to be printed to screen
void func_set_colour(Func* func, int colour)
{
    func->colour = colour;
}

// set string to be printed to screen
void func_set_str(Func* func, const char* str)
{
    func->str = str;
}

// create, refresh then destroy (drawn on the screen)
void func(double (*func)(double x), int colour, const char *str)
{
    // create pointer
    Func *function = func_create(func, colour, str);

    // draw to screen
    func_refresh(function);

    // destroy pointer
    free(function);
    function = NULL;
}
