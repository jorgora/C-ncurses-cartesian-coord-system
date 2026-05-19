#ifndef NUMBERLINE_H_
#define NUMBERLINE_H_

typedef struct
{
    int x;
    int y;
    int length;
    int colour;
} Numberline;

//create routine in memory
Numberline* numberline_create(int x, int y, int length, int colour);

//destroy routine in memory
void numberline_destroy(Numberline* numberline);

//draw to ncurses screen
void numberline_refresh(Numberline* numberline);

// create, refresh then destroy, drawn on screen
void numberline(int x, int y, int length, int colour);

#endif // NUMBERLINE_H_
