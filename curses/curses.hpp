#ifndef INCLUDE_CURSES
#define INCLUDE_CURSES

#include <iostream>
#include <vector>
#include <algorithm>
#include <ncurses.h>

// #include "common.hpp"
// #include <menu.h>
// #include <form.h>

class Curses
{
private:
    // std::shared_ptr<WINDOW> window;
    int colsMax;
    int linesMax;
public:
    Curses(int _colsMax, int _linesMax) : colsMax {_colsMax}, linesMax {_linesMax}
    {
        initscr();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);
    };

    int clear()
    {
        return clear();
    }
    
    int end()
    {
        return endwin();
    }

    int refresh()
    {
        return refresh();
    }

    bool isSizeFit()
    {
        return ((COLS < colsMax) || (LINES < linesMax)) ? false : true;
    }

    void startColor()
    {
        start_color();
    }

    int initColor(int index, int foreground, int background)
    {
        return init_pair(index, foreground, background);
    }
 
};


#endif