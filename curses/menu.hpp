#include <iostream>
#include <vector>
#include <curses.h>


namespace Curses
{
    class Menu
    {
    private:
        std::vector<ITEM *> itemList;
        std::unique_ptr<MENU *> menu_ptr;
        
    public:
        Menu() = default;

        void create(std::vector<std::string> &list)
        {
            /* Initialize items */
            for(uint32_t i = 0; i < list.size(); ++i)
            {
                itemList.push_back(new_item(list.at(i).c_str(), ""));
            }

            /* Create menu */
            menu_ptr = std::make_unique<MENU *>(new_menu((ITEM **) &itemList[0]));
        }

        void post()
        {
            post_menu(*menu_ptr.get());
        }

        void unpost()
        {
            unpost_menu(*menu_ptr.get());
        }

        MENU* getMenu() const 
        { 
            return *menu_ptr.get();
        }

        void driveMenu(int type)
        {
            menu_driver(*menu_ptr.get(), type);
        }

        void freeMenuItems()
        {
            ITEM **items = menu_items(static_cast<const MENU*>(getMenu()));
            int itemCount = item_count(static_cast<const MENU*>(getMenu()));

            for(int i = 0; i < itemCount; i++)
            {
                free_item(items[i]);
            }
            // free_menu(getMenu());
        }

        void updateMenu(std::vector<std::string> &list)
        {   
            itemList.clear();
            for (uint32_t i = 0; i < list.size(); ++i)
                itemList.push_back(new_item(list.at(i).c_str(), ""));
                
            int ret = set_menu_items(getMenu(), itemList.data());
            int itemCount = item_count(static_cast<const MENU*>(getMenu()));
            
        }
    };
}