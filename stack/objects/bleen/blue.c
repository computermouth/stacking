
#include "../../stack.h"
#include "blue.h"

shape blue(){
	
	short x[] = {100, 200, 200, 100};
	short y[] = {200, 200, 100, 100};
	short points = 4;
	short color[] = {0, 0, 255, 255};
	short z = 1;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
