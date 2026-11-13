#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "../headers/func.h"
#include "../headers/point.h"

// exit codes
#define FAIL -1
#define SUCCESS 0

// create routine in memory
Func* func_create(double (*func) (double x), int colour, const char* str)
{
    // handle NULL function error
    if(func == NULL) return NULL;

    // handle invalid colour error
    if(colour < 1) return NULL;

    // handle NULL str error
    if(str == NULL) return NULL;

    // create pointer
    Func* function = malloc(sizeof(Func));

    // handle malloc error 
    if(function == NULL) return NULL;

    // assign data
    function->func = func;
    function->colour = colour;
    function->str = strdup(str);

    // exit
    return function;
}


// set function pointer of func to be printed
int func_set_func(Func* func, double (*function) (double x))
{
    // handle NULL pointer error
    if (func == NULL) return FAIL;

    // handle NULL function error
    if (function == NULL) return FAIL;

    // assign data
    func->func = function;

    // exit
    return SUCCESS;
}

// set colour to be printed to screen
int func_set_colour(Func* func, int colour)
{
    // handle NULL pointer error
    if (func == NULL) return FAIL;

    // handle invalid colour error
     if (colour < 1) return FAIL;

    // assign data
    func->colour = colour;

    // exit
    return SUCCESS;
}


// set string to be printed to screen
int func_set_str(Func* func, const char* str)
{
    // handle NULL pointer error
    if (func == NULL) return FAIL;

    // handle NULL str error
    if(str == NULL) return FAIL;

    // assign data
    func->str = strdup(str);

    // exit
    return SUCCESS;
}


// draw on ncurse screen
int func_refresh(Func* func)
{
    // handle NULL pointer error
    if (func == NULL) return FAIL;

    // get maximums from screen size
    int max_y = 0;
    int max_x = 0;
    getmaxyx(stdscr, max_y, max_x);
    
    // draw function
    for(int i = -100; i < max_x; i++)
    { 
        point(i, floor(func->func(i)), func->colour, func->str);   
    }

    // exit
    return SUCCESS;
}

// create, refresh then destroy (drawn on the screen)
int func(double (*func)(double x), int colour, const char *str)
{
    // handle invalid colour error
     if (colour < 1) return FAIL;

    // handle NULL str error
    if (str == NULL) return FAIL;
    
    // create pointer
    Func *function = func_create(func, colour, str);

    // handle malloc error
    if (function == NULL) return FAIL;

    // draw to screen
    func_refresh(function);

    // free memory
    free(function->str);
    free(function);
    function = NULL;

    // exit
    return SUCCESS;
}
