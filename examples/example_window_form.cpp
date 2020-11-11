#include <iostream>
#include "curses/curses.hpp"

int main(int argc, char const *argv[])
{
    int colsMin {40}, linesMin {23}; 

    CursesUI::Curses curses { colsMin, linesMin };
    curses.startColor();
    curses.initColor(0, COLOR_WHITE, COLOR_BLACK);
    curses.initColor(1, COLOR_GREEN, COLOR_BLACK);

    CursesUI::Text text {};

    if(!curses.isSizeFit())
    {
        curses.refreshWin();
        
        text.write(0, 0, "Curses size is should be greater then" +
            std::to_string(colsMin) + "x" + std::to_string(linesMin), true);
        getch();
        curses.clearWin();
        curses.endWin();
        return -1;
    }

    CursesUI::Window window {0 ,0, COLS, 3};
    CursesUI::Form form {1, COLS-4, 0, 1, 0, 0, A_UNDERLINE, O_STATIC };

    window.create(form.getForm());

    window.keypadEnable(true);

    curses.refreshWin();
    form.post();
    window.refresh();

    int c;

    while((c = wgetch(window.getWindow())) != KEY_F(1))
	{
        switch(c)
	    {
        case KEY_DC : //KEY_DELETE
            form.driveForm(REQ_CLR_FIELD);
            break;

        case 127: // KEY_BACKSPACE
        case KEY_BACKSPACE:
            form.driveForm(REQ_DEL_PREV);
            break;

        default:
            form.driveForm(REQ_END_LINE);
            form.driveForm(c);
            break;
        }
        window.refresh();
	}

    form.unpost();
    curses.clearWin();
    curses.endWin();
    
    return 0;
}