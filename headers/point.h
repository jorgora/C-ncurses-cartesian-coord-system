#ifndef POINT_H_
#define POINT_H_

// struct definition
typedef struct
{
    int x;
    int y;
    int colour;
    char* str;
} Point;

// create routine for memory
Point* point_create(int x, int y, int colour, const char* str);

// move current coordinate by amount
int point_move(Point* point, int x, int y);

// move to coordinate (x, y)
int point_set(Point* point, int x, int y);

// set string to be printed
int point_set_str(Point* point, const char* str);

// set colour to be printed
int point_set_colour(Point* point, int colour);

// draw to ncurses screen
int point_refresh(Point* point);

// create, refresh then destroy (drawn on screen)
int point(int x, int y, int colour, const char* str);

#endif // POINT_H_
