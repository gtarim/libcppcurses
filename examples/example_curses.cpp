#include <iostream>
#include "curses/curses.hpp"

#define MIN_COLS    40
#define MIN_LINES   23

int main(int argc, char const *argv[])
{

    Curses curses { 40, 23 };

    if(!curses.isSizeFit())
    {
        // curses.refresh();
        printw("Curses size is should be greater then %dx%d",COLS,LINES);
        getch();
        curses.clear();
        curses.end();
    }
    // else
    // {
    //     curses.refresh();
    //     printw("Curses is fit");
    //     getch();
    //     curses.clear();
    //     curses.end();
    // }

    return 0;
}
