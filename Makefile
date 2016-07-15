OBJS = main.c stack.c

OBJ_NAME = stacking

.PHONY: all clean lint

all: $(OBJS)
	gcc $(OBJS) -Wall -o $(OBJ_NAME)

clean:
	rm *.o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

memtest:
	valgrind --track-origins=yes --leak-check=yes ./$(OBJ_NAME)

lint:
	cppcheck --language=c --enable=warning,style --template=gcc *.c *.h
