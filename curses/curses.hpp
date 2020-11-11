#pragma once

#include "common.hpp"

#include "curses.hpp"
#include "window.hpp"
#include "menu.hpp"
#include "text.hpp"
#include "form.hpp"
#include "panel.hpp"

namespace CursesUI
{
    class Curses
    {
    private:
        int colsMin;
        int linesMin;
    public:
        Curses(int _colsMin, int _linesMin)
        :   colsMin{_colsMin}, 
            linesMin{_linesMin}
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
            return ((COLS < colsMin) || (LINES < linesMin)) ? false : true;
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

        void enableBold(bool flag)
        {
            if(flag)
            {
                attron(A_BOLD);
            }
            else
            {
                attroff(A_BOLD);
            }
        }

        void enableUnderline(bool flag)
        {
            if(flag)
            {
                attron(A_UNDERLINE);
            }
            else
            {
                attroff(A_UNDERLINE);
            }
        }

        void enableItalic(bool flag)
        {
            if(flag)
            {
                attron(A_ITALIC);
            }
            else
            {
                attroff(A_ITALIC);
            }
        }
    };
}