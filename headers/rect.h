#ifndef RECT_H_
#define RECT_H_

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    int colour;
    const char* str; 
} Rect;

// create routine for memory
Rect* rect_create(int x, int y, int width, int height, int colour, const char* str);

// destroy routine for memory
void rect_destroy(Rect* rect);

// draw to ncurses screen
void rect_refresh(Rect* rect);

// set colour of rect
void rect_set_colour(Rect* rect, int colour);

// set string of rect
void rect_set_str(Rect* rect, const char* str);

// create, refresh then destroy (draw to screen)
void rect(int x, int y, int width, int height, int colour, const char* str);

#endif // RECT_H_


