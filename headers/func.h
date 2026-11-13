#ifndef FUNC_H_
#define FUNC_H_

typedef struct
{
    double (*func) (double);
    int colour;
    char* str;
} Func;

// create routine in memory
Func* func_create(double (*func) (double), int colour, const char* str);

// set function pointer of func to be printed
int func_set_func(Func* func, double (*function) (double x));

// set colour to be printed 
int func_set_colour(Func* func, int colour);

// set string to be printed 
int func_set_str(Func* func, const char* str);

// draw on ncurses screen
int func_refresh(Func* func);

// create, refresh then destroy (drawn on the screen)
int func(double (*func) (double x), int colour, const char* str);

#endif // FUNC_H_
