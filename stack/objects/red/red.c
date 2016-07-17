
#include "../../stack.h"
#include "red.h"

shape red(){
	
	short x[] = {400, 500, 500, 400};
	short y[] = {500, 500, 400, 400};
	short points = 4;
	short color[] = {255, 0, 0, 255};
	short z = 4;
	
	shape sh = init_shape(x, y, points, color, z);
	
	return sh;
}
