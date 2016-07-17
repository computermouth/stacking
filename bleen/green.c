
#include "stack.h"
#include "green.h"

shape green(){
	
	short x[] = {300, 600, 600, 300};
	short y[] = {600, 600, 300, 300};
	short points = 4;
	short color[] = {0, 255, 0, 255};
	short z = 7;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
