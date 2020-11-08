#pragma once

#include "common.hpp"

#include "curses.hpp"
#include "window.hpp"
#include "menu.hpp"

namespace CursesUI
{
    class Curses
    {
    private:
        int colsMax;
        int linesMax;
    public:
        Curses(int _colsMax, int _linesMax)
        :   colsMax{_colsMax}, 
            linesMax{_linesMax}
        {
            initscr();
            cbreak();
            noecho();
        }

        int clearWin()
        {
            return clear();
        }
        
        int endWin()
        {
            return endwin();
        }

        int refreshWin()
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

        void enableColor(int color, bool flag)
        {
            if(flag)
            {
                attron(COLOR_PAIR(color));
            }
            else
            {
                attroff(COLOR_PAIR(color));
            }
        }
    };
}