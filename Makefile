SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
SOURCES_H := $(shell find $(SOURCEDIR) -name '*.h')

MAIN_NAME = stacking

LIBS = -lSDL2 -lSDL2_gfx

.PHONY: all clean lint

all: $(MAIN)
	gcc $(SOURCES) -Wall -o $(MAIN_NAME) $(LIBS)

clean:
	rm $(MAIN_NAME)

run:
	./stacking

re: clean all run

memtest:
	valgrind --track-origins=yes --leak-check=yes ./$(MAIN_NAME)

lint:
	cppcheck --language=c --enable=warning,style --template=gcc\
 $(SOURCES) $(SOURCES_H)
