#pragma once

#include "common.hpp"

namespace CursesUI
{
    class Text
    {          
    public:
        Text() = default;

        void write(int x, int y, std::string str, bool colored, int color = 0)
        {
            if(colored) attron(COLOR_PAIR(color)); 
            mvprintw(y,x, str.c_str()); 
            if(colored) attroff(COLOR_PAIR(color));
        }
    };
};