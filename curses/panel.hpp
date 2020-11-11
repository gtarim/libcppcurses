#pragma once

#include "common.hpp"

namespace CursesUI
{
    class Panel
    {
    private:
        std::unique_ptr<PANEL*> panel_ptr;
        int height, width, y, x;
    public:
        Panel() = default;
        
        Panel(WINDOW *window) 
        {
            panel_ptr = std::make_unique<PANEL*>(new_panel(window));
        }

        void setWindow(WINDOW *window)
        {
            panel_ptr = std::make_unique<PANEL*>(new_panel(window));
        }

        PANEL* getPanel() const { return *panel_ptr.get(); }
        
        void updatePanel()
        {
            update_panels();
            doupdate();
        }
    


    };

}