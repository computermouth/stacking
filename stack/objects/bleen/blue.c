
#include "../../stack.h"
#include "blue.h"

shape blue(){
	
	short x[] = {150, 250, 250, 150};
	short y[] = {250, 250, 150, 150};
	short points = 4;
	short color[] = {0, 0, 255, 255};
	short z = 1;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
