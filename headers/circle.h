#ifndef CIRCLE_H_
#define CIRCLE_H_

typedef struct
{
    int x;
    int y;
    int radius;
    int colour;
    char* str; 
} Circle;

// create routine for memory
Circle* circle_create(int x, int y, int radius, int colour, const char* str);

//draw to ncurses screen
int circle_refresh(Circle* circle);

//create, refresh then destroy (draw to screen)
int circle(int x, int y, int radius, int colour, const char* str);

#endif // CIRCLE_H_
