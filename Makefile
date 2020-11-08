########################################################################
# Description:
#  Makefile
########################################################################

ifneq ($TARGET),)
CROSS_TARGET = $(TARGET)-
endif

CC=$(CROSS_TARGET)gcc
CXX=$(CROSS_TARGET)g++

# Name of the application
OUTFILE = kman

SRC = examples
BUILD = build

# List of object files
OBJECTS = \
	$(SRC)/example_text.o
	# $(SRC)/example_window_menu.o
	# $(SRC)/example_curses.o

INCLUDE	:=-I$(SYSROOT)/usr/include -I$(SYSROOT)/usr/local/include -I./

ifneq ($(SYSROOT),)
CFLAGS	:=--sysroot=$(SYSROOT) 
endif

INCLUDE +=-I$(SRC) -I$(SRC)/kman 
LFLAGS 	=-lmenu -lcurses -lpthread
CFLAGS 	+=$(INCLUDE) $(CROSS_CC_FLAGS)

all: $(OUTFILE)

$(OUTFILE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(BUILD)/$@ $(LFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: $(SRC)/%.c
	$(CC) -c $(CFLAGS) $< -o $@

%.o: $(SRC)/%.cc
	$(CXX) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	-rm $(SRC)/*.o $(BUILD)/*.map $(BUILD)/$(OUTFILE)