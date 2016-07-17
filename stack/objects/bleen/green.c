
#include "../../stack.h"
#include "green.h"

shape green(){
	
	short x[] = {200, 300, 300, 200};
	short y[] = {300, 300, 200, 200};
	short points = 4;
	short color[] = {0, 255, 0, 255};
	short z = 2;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
