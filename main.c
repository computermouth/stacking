
#include <stdio.h>

#include "stack.h"

int main(){
	stack st = init_stack();

	object ob = init_object();
	
	short x[] = {123, 345, 456, 567};
	short y[] = {123, 345, 456, 567};
	short points = 4;
	short color[] = {0, 255, 0, 255};
	short z = 0;
	
	shape sh1 = init_shape(x, y, points, color, z);
	ob = push_object(ob, sh1);
	shape sh2 = init_shape(x, y, points, color, z);
	ob = push_object(ob, sh2);
	shape sh3 = init_shape(x, y, points, color, z);
	ob = push_object(ob, sh3);
	
	st = push_stack(st, ob);
	
	print_stack(st);
	
	
	del_object(ob);
	del_stack(st);
	
	return 0;
}
