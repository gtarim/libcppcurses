#include <form.h>

namespace Curses
{
    class Form
    {
    private:
        std::unique_ptr<FORM *> form_ptr;
        FIELD *field[2];
    public:
        Form() = default;

        void create(int rows, int cols, int frow, int fcol, int nrows, int nbuf, chtype ch_type, Field_Options field_option)
        {
            field[0] = new_field(rows, cols, frow, fcol, nrows, nbuf);
            field[1] = NULL;
            set_field_back(field[0], ch_type); 
            field_opts_off(field[0], field_option);

            form_ptr = std::make_unique<FORM *>(new_form(field));
        }

        void post()
        {
            post_form(*form_ptr.get());
        }

        void unpost()
        {
            unpost_form(*form_ptr.get());
        }

        FORM* getForm() const 
        { 
            return *form_ptr.get();
        }

        void driveForm(int type)
        {
            form_driver(*form_ptr.get(), type);
        }

        void freeForm()
        {	
            free_field(field[0]);
            free_field(field[1]); 

            free_form(*form_ptr.get());
        }
        
    };

}
