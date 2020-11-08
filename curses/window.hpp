#pragma once

#include "common.hpp"

namespace CursesUI
{
    class Window
    {
    private:
        std::shared_ptr<WINDOW*> window_ptr;
        int height, width, y, x;
    public:
        Window() 
        {
            window_ptr = std::make_shared<WINDOW*>(newwin(LINES/2, COLS, 0, 0));
        }
        
        Window(int x, int y) 
        {
            window_ptr = std::make_shared<WINDOW*>(newwin(LINES/2, COLS, y, x));
        }

        Window(int _x, int _y, int _width, int _height) :
         x{_x}, 
         y{_y}, 
         width{_width},
         height{_height}
        {
            window_ptr = std::make_shared<WINDOW*>(newwin(height, width, y, x));
        }

        void setWindow(int x, int y, int width, int height)
        {
            window_ptr = std::make_shared<WINDOW*>(newwin(height, width, y, x));
        }

        void create(MENU * menu_ptr)
        {
            set_menu_win(menu_ptr, *window_ptr.get());
            set_menu_sub(menu_ptr, derwin(*window_ptr.get(), height-2, width-2, 1, 1));
            set_menu_format(menu_ptr, height-2, 1);
            set_menu_mark(menu_ptr, " ");

            box(*window_ptr.get(), 0, 0);
        }

        void create(FORM * form_ptr)
        {
            set_form_win(form_ptr, *window_ptr.get());
            set_form_sub(form_ptr, derwin(*window_ptr.get(), height-2, width-2, 1, 1));

            box(*window_ptr.get(), 0, 0);
        }

        void changeEnable(bool enable)
        {
            if(enable)
            {
                wattron(getWindow(),COLOR_PAIR(1));
                box(*window_ptr.get(), 0, 0);
                wattroff(getWindow(),COLOR_PAIR(2));
            }
            else
            {
                wattron(getWindow(),COLOR_PAIR(2));
                box(*window_ptr.get(), 0, 0);
                wattroff(getWindow(),COLOR_PAIR(1));
            }
            
        }

        WINDOW* getWindow() const { return *window_ptr.get(); }

        void keypadEnable(bool flag) const { keypad(*window_ptr.get(),flag); }
        
        void refresh()
        {
            wrefresh(*window_ptr.get());
        }
        
        void updateWindow(MENU * menu_ptr)
        {
            set_menu_sub(menu_ptr,derwin(*window_ptr.get(), height-2, width-2, 1, 1));
            // box(*window_ptr.get(), 0, 0);
        }
    };
}