#include <iostream>
#include "curses/curses.hpp"

int main(int argc, char const *argv[])
{

    CursesUI::Curses curses { 40, 23 };
    curses.startColor();
    curses.initColor(0, COLOR_WHITE, COLOR_BLACK);
    curses.initColor(1, COLOR_GREEN, COLOR_BLACK);

    CursesUI::Text text {};

    if(!curses.isSizeFit())
    {
        curses.refreshWin();

        
        text.write(0, 0, "Curses size is should be greater then", true);
        // curses.enableColor(0,true);
        // printw("Curses size is should be greater then %dx%d",COLS,LINES);
        // curses.enableColor(0,false);
        getch();
        curses.clearWin();
        curses.endWin();
    }else
    {
        
        curses.refreshWin();
        text.write(0, 0, "Curses size is " 
                    + std::to_string(COLS) 
                    + "x" 
                    + std::to_string(LINES), true);
        getch();
        curses.clearWin();
        curses.endWin();
    }
    
    return 0;
}