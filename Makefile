
BLEEN_DIR = bleen/
BLEEN_SH = blue.c green.c
BLEEN = $(addprefix $(BLEEN_DIR), $(BLEEN_SH))
OBJS += $(BLEEN)

PURP_DIR = purp/
PURP_SH = purp.c
PURP = $(addprefix $(PURP_DIR), $(PURP_SH))
OBJS += $(PURP)

RED_DIR = red/
RED_SH = red.c
RED = $(addprefix $(RED_DIR), $(RED_SH))
OBJS += $(RED)

ALL_DIR = $(BLEEN_DIR) $(RED_DIR) $(PURP_DIR)

MAIN = main.c stack.c $(OBJS)
MAIN_NAME = stacking

.PHONY: all clean lint

all: $(MAIN)
	gcc $(MAIN) -Wall -o $(MAIN_NAME)

clean:
	rm *.o $(MAIN_NAME) $(addsuffix *.o, $(ALL_DIR))

memtest:
	valgrind --track-origins=yes --leak-check=yes ./$(OBJ_MAIN)

lint:
	cppcheck --language=c --enable=warning,style --template=gcc\
 *.c *.h\
 $(addsuffix *.c, $(ALL_DIR))\
 $(addsuffix *.h, $(ALL_DIR))
