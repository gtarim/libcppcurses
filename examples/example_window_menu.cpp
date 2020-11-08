
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
        return -1;
    }
    
    CursesUI::Menu menu{};
    CursesUI::Window menuWindow {0,0, COLS-2, LINES-2};
    
    // creting menu elements
    std::vector<std::string> listMenu {"gokhantarim"};

    menu.create(listMenu);

    menuWindow.keypadEnable(true);
    menuWindow.create(menu.getMenu());

    curses.refreshWin();
    menu.post();
    menuWindow.refresh();

    getch();
    curses.clearWin();
    curses.endWin();


    return 0;
}
