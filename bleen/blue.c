
#include "stack.h"
#include "blue.h"

shape blue(){
	
	short x[] = {300, 600, 600, 300};
	short y[] = {600, 600, 300, 300};
	short points = 4;
	short color[] = {0, 0, 255, 255};
	short z = 7;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
