#include <ncurses.h>

void colour_pairs_init()
{
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_WHITE);
    init_pair(4, COLOR_WHITE, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_RED);

    init_pair(6, COLOR_GREEN, COLOR_BLACK);
    init_pair(7, COLOR_GREEN, COLOR_WHITE);
    init_pair(8, COLOR_WHITE, COLOR_GREEN);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);

    init_pair(10, COLOR_YELLOW, COLOR_BLACK);
    init_pair(11, COLOR_YELLOW, COLOR_WHITE);
    init_pair(12, COLOR_WHITE, COLOR_YELLOW);
    init_pair(13, COLOR_BLACK, COLOR_YELLOW);

    init_pair(14, COLOR_BLUE, COLOR_BLACK);
    init_pair(15, COLOR_BLUE, COLOR_WHITE);
    init_pair(16, COLOR_WHITE, COLOR_BLUE);
    init_pair(17, COLOR_BLACK, COLOR_BLUE);

    init_pair(18, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(19, COLOR_MAGENTA, COLOR_WHITE);
    init_pair(20, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(21, COLOR_BLACK, COLOR_MAGENTA);

    init_pair(22, COLOR_CYAN, COLOR_BLACK);
    init_pair(23, COLOR_CYAN, COLOR_WHITE);
    init_pair(24, COLOR_WHITE, COLOR_CYAN);
    init_pair(25, COLOR_BLACK, COLOR_CYAN);


    init_pair(26, COLOR_BLACK, COLOR_BLACK);
    init_pair(27, COLOR_WHITE, COLOR_WHITE);
}


