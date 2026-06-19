#ifndef CROSS_H_
#define CROSS_H_

// struct definition
typedef struct
{
    int x;
    int y;
    int colour;
    const char* str;
} Cross;

// create routine for memory
Cross* cross_create(int x, int y, int colour);

// destroy routine for memory
void cross_destroy(Cross* cross);

// move current coordinate by amount
void cross_move(Cross* cross, int x, int y);

// move to coordinate (x, y)
void cross_set(Cross* cross, int x, int y);

// draw to ncurses screen
void cross_refresh(Cross* cross);

// set colour to be printed
void cross_set_colour(Cross* cross, int colour);

// this needs update. it doesn't use the point object
void cross(int x, int y);

#endif // CROSS_H_
