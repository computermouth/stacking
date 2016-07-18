
#include "../../stack.h"
#include "green.h"

shape green(){
	
	short x[] = {170, 270, 270, 170};
	short y[] = {270, 270, 170, 170};
	short points = 4;
	short color[] = {0, 255, 0, 255};
	short z = 2;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
