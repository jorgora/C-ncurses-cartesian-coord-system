#include <math.h>
#include <stdlib.h>
#include <ncurses.h>

#include "../headers/point.h"
#include "../headers/rect.h"
#include "../headers/cross.h"
#include "../headers/colour_pairs.h"
#include "../headers/func.h"
#include "../headers/numberline.h"

double big_sin(double x)
{
 return sin(x/10) * 10; 
}

double big_cos(double x)
{
 return cos(x/10) * 10; 
}

double big_tan(double x)
{
 return tan(x/10) * 10; 
}

void draw_face()
{
    // face background
    rect(-40, 1, 26, 20, 20, "GW");

    // mouth
    rect(-38, 3, 22, 2, 5, "5%");

    // mouth line
    for(int i = -38; i < - 15; i ++)
    {
        point(i, 4, 0, "64");
    }

    // left eye
    rect(-38, 10, 8, 8, 27, " #");
    rect(-37, 11, 6, 6, 26, "B0");
    point(-32, 16, 27, " #");

    // right eye
    rect(-24, 10, 8, 8, 27, " #");
    rect(-23, 11, 6, 6, 26, "B0");
    point(-18, 16, 27, " #");

    // nose line
    for(int i = 7; i < 19; i++)
    {
        point(-27, i, 26, "B0");
    }

    // nose body
    for(int i = -29; i < -24; i++)
    {
        point(i, 7, 22, "NS");
        point(i, 8, 22, "NS");
    }

    // hair
    for(int i = -40; i < -13; i++)
    {
        point(i, 22, 15, "NS");
        point(i, 23, 15, "NS");
    }
}


int main(void)
{
    //init screen (start ncurses)
    //all ncurses code between initscr() and endwin()
    initscr();

    //handle no colour error
    if(!has_colors())
    {
        printw("Terminal does not support colours");
        getch();
        return EXIT_FAILURE;
    }

    // start ncurses colors
    start_color();

    // make a lot of colour pairs
    colour_pairs_init();

    // create window pointer
    WINDOW* win = newwin(10, 20, 10, 10);

    // refresh main screen to match whats in memory
    // equiv wrefresh(stdscr)
    refresh();

    // refresh window
    wrefresh(win);

    // dot grid
    rect(-70, -70, 150, 150, 6, ". ");

    // numbered cross
    cross(0, 0);

    // draw face
    draw_face();

    // numberline
    numberline(4, 14, 15, 5);

    // functions
    func(big_sin, 1, "GO");
    func(big_cos, 2, "PO");

    //circle (not working)
    //circle(-10, -10, 10, 8, "RT");
    
    // refresh window
    wrefresh(win);

    // refresh main screen to match whats in memory
    // equiv wrefresh(stdscr)
    refresh();

    // wait for keypress - returns int value of key
    getch();
    
    //deallocate memory  (end ncurses)
    endwin();

    // exit program
    return EXIT_SUCCESS;
}


