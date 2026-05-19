#ifndef POINT_H_
#define POINT_H_

typedef struct
{
    int x;
    int y;
    int colour;
    const char* str;
} Point;

// create routine for memory
Point* point_create(int x, int y, int colour, const char* str);

// destroy rountine for memory
void point_destroy(Point * point);

// move current coordinate by amount
void point_move(Point* point, int x, int y);

// move to coordinate (x, y)
void point_set(Point* point, int x, int y);

// set string that will be print
void point_set_str(Point* point, const char* str);

// set colour of point
void point_set_colour(Point* point, int colour);

// draw to ncurses screen
void point_refresh(Point* point);

// create, refresh then destroy, drawn on screen
void point(int x, int y, int colour, const char* str);

#endif // POINT_H_
