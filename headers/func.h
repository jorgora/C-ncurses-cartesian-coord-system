#ifndef FUNC_H_
#define FUNC_H_

typedef struct
{
    double (*func) (double);
    int colour;
    const char* str;
} Func;

//create routine for memory
Func* func_create(double (*func) (double), int colour, const char* str);

void func_destroy(Func* func);

void func_refresh(Func* func);

void func(double (*func) (double x), int colour, const char* str);

#endif // FUNC_H_
