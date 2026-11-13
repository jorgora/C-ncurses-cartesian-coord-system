#ifndef RECT_H_
#define RECT_H_

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    int colour;
    char* str; 
} Rect;

// create routine for memory
Rect* rect_create(int x, int y, int width, int height, int colour, const char* str);

// set colour to be printed
int rect_set_colour(Rect* rect, int colour);

// set string to be printed
int rect_set_str(Rect* rect, const char* str);

// draw to ncurses screen
int rect_refresh(Rect* rect);

// create, refresh then destroy (drawn to screen)
int rect(int x, int y, int width, int height, int colour, const char* str);

#endif // RECT_H_
