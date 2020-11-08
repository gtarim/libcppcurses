#include <iostream>
#include "curses/curses.hpp"

int main(int argc, char const *argv[])
{

    CursesUI::Curses curses { 40, 23 };
    curses.startColor();
    curses.initColor(0, COLOR_WHITE, COLOR_BLACK);
    curses.initColor(1, COLOR_GREEN, COLOR_BLACK);

    if(!curses.isSizeFit())
    {
        curses.refreshWin();
        curses.enableColor(0,true);
        printw("Curses size is should be greater then %dx%d",COLS,LINES);
        curses.enableColor(0,false);
        getch();
        curses.clearWin();
        curses.endWin();
    }
    else
    {
        curses.refreshWin();
        curses.enableColor(1,true);
        printw("Curses is fit");
        curses.enableColor(1,false);
        getch();
        curses.clearWin();
        curses.endWin();
    }

    return 0;
}