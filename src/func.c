#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/func.h"
#include "../headers/point.h"

Func* func_create(double (*func) (double x), int colour, const char* str)
{
    Func* function = malloc(sizeof(Func));
    function->func = func;
    function->colour = colour;
    function->str = str;
}

void func_destroy(Func* func)
{
    free(func);
}


void func_refresh(Func* func)
{
    //get maximums from screen size (get to get centre point by /2) (it updates the vars)
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);
    

    for(int i = -100; i < max_x; i++)
    { 
        point(i, floor(func->func(i)), func->colour, func->str);   
    }
    
}

void func(double (*func) (double x), int colour, const char* str)
{
    Func* function = func_create(func, colour, str);
    func_refresh(function);
    func_destroy(function);
}
