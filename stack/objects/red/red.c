
#include "../../stack.h"
#include "red.h"

shape red(){
	
	short x[] = {190, 290, 290, 190};
	short y[] = {290, 290, 190, 190};
	short points = 4;
	short color[] = {255, 0, 0, 255};
	short z = 4;
	
	shape sh = init_shape(x, y, points, color, z);
	
	return sh;
}
