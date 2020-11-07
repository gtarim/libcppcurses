#include <iostream>
#include <curses.h>
#include <form.h>

namespace Curses
{
    class Field
    {
    private:
        std::unique_ptr<FIELD *> field_ptr;
        FIELD *field[2];
    public:
        void create(int rows, int cols, int frow, int fcol, int nrows, int nbuf)
        {
            field_ptr = std::make_unique<FIELD *>(new_field(rows, cols, frow, fcol, nrows, nbuf));
        }
        
        void optionRoutines(Form_Options  opts)
        {
            field_opts_off(*field_ptr.get(), opts);
        }

        void setFieldBack(chtype attribute)
        {
            set_field_back(*field_ptr.get(),attribute);
        }

        FIELD * getField() const
        {
            return *field_ptr.get();
        }

        void freeField()
        {
	        free_field(*field_ptr.get());
        }
    };
}