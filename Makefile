objects := $(shell find . -type f -iname "*.cpp" | sed 's/.cpp//g') 
all: $(objects)

CC := g++
CFLAGS := -g $(CFLAGS_INC)
LDFLAGS := -lSDL2 -lSDL2_ttf


$(objects): %: %.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) 
