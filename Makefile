OBJ_DIR = objects/

BLEEN_DIR = bleen/
BLEEN_SH = blue.c green.c
BLEEN = $(addprefix $(BLEEN_DIR), $(BLEEN_SH))
S_OBJS += $(BLEEN)

PURP_DIR = purp/
PURP_SH = purp.c
PURP = $(addprefix $(PURP_DIR), $(PURP_SH))
S_OBJS += $(PURP)

RED_DIR = red/
RED_SH = red.c
RED = $(addprefix $(RED_DIR), $(RED_SH))
S_OBJS += $(RED)

OBJS = $(addprefix $(OBJ_DIR), $(S_OBJS))

ALL_DIR = $(BLEEN_DIR) $(RED_DIR) $(PURP_DIR)

MAIN = main.c stack.c $(OBJS)
MAIN_NAME = stacking

.PHONY: all clean lint

all: $(MAIN)
	gcc $(MAIN) -Wall -o $(MAIN_NAME)

curr: main.c stack/stack.c stack/objects/o_bleen.c stack/objects/bleen/*.c
	gcc main.c stack/stack.c stack/objects/o_bleen.c stack/objects/bleen/*.c -Wall -o stacking
clean:
	rm *.o $(MAIN_NAME) $(addsuffix *.o, $(ALL_DIR))

memtest:
	valgrind --track-origins=yes --leak-check=yes ./$(MAIN_NAME)

lint:
	cppcheck --language=c --enable=warning,style --template=gcc\
 *.c *.h\
 $(addsuffix *.c, $(addprefix $(OBJ_DIR), $(ALL_DIR)))\
 $(addsuffix *.h, $(addprefix $(OBJ_DIR), $(ALL_DIR)))
