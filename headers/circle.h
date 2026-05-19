#ifndef CIRCLE_H_
#define CIRCLE_H_

typedef struct
{
    int x;
    int y;
    int radius;
    int colour;
    const char* str; 
} Circle;

// create routine for memory
Circle* circle_create(int x, int y, int radius, int colour, const char* str);

// destroy routine for memory
void circle_destroy(Circle* circle);

//draw to ncurses screen
void circle_refresh(Circle* circle);

//create, refresh then destroy (draw to screen)
void circle(int x, int y, int radius, int colour, const char* str);

#endif // CIRCLE_H_
