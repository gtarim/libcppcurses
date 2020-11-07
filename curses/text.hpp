#include <iostream>
#include <curses.h>

namespace Curses
{
    class Text
    {          
    public:
        Text() = default;

        void write(int x, int y, std::string str, bool colored)
        {
            if(colored) attron(COLOR_PAIR(3)); 
            mvprintw(y,x, str.c_str()); 
            if(colored) attroff(COLOR_PAIR(3));
        }
    };
};