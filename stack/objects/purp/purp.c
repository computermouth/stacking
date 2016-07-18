
#include "../../stack.h"
#include "purp.h"

shape purp(){
	
	short x[] = {120, 220, 220, 120};
	short y[] = {220, 220, 120, 120};
	short points = 4;
	short color[] = {255, 0, 255, 255};
	short z = 3;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
