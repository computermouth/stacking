
#include "../../stack.h"
#include "purp.h"

shape purp(){
	
	short x[] = {300, 400, 400, 300};
	short y[] = {400, 400, 300, 300};
	short points = 4;
	short color[] = {255, 0, 255, 255};
	short z = 3;
	
	shape sh = init_shape(x, y, points, color, z);

	return sh;
}
