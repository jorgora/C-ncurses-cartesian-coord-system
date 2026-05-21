#ifndef FUNC_H_
#define FUNC_H_

// struct definition
typedef struct
{
    double (*func) (double);
    int colour;
    const char* str;
} Func;

// create routine in memory
Func* func_create(double (*func) (double), int colour, const char* str);

// destroy routine in memory
void func_destroy(Func* func);

// draw on ncurses screen
void func_refresh(Func* func);

// set function pointer of func to be printed
void func_set_func(Func* func, double (*function) (double x));

// set colour to be printed to screen
void func_set_colour(Func* func, int colour);

// set string to be printed to strin
void func_set_str(Func* func, const char* str);

// create, refresh then destroy the point, leaving it drawn on the screen
void func(double (*func) (double x), int colour, const char* str);

#endif // FUNC_H_
