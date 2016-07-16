
#include <stdio.h>

#include "stack.h"

int main(){
	stack st = init_stack();

	object ob = init_object();
	object ob2 = init_object();
	
	short x[] = {123, 345, 456, 567};
	short y[] = {123, 345, 456, 567};
	short points = 4;
	short color[] = {0, 255, 0, 255};
	short z = 0;
	
	shape sh1 = init_shape(x, y, points, color, z);
	ob = push_object(ob, sh1);
	
	short x2[] = {123, 345, 456, 567};
	short y2[] = {123, 345, 456, 567};
	short points2 = 4;
	short color2[] = {0, 255, 0, 255};
	short z2 = 0;
	
	shape sh2 = init_shape(x2, y2, points2, color2, z2);
	ob = push_object(ob, sh2);
	
	short x3[] = {123, 345, 456, 567};
	short y3[] = {123, 345, 456, 567};
	short points3 = 4;
	short color3[] = {0, 255, 0, 255};
	short z3 = 0;
	
	shape sh3 = init_shape(x3, y3, points3, color3, z3);
	ob2 = push_object(ob2, sh3);
	
	st = push_stack(st, ob);
	st = push_stack(st, ob2);
	
	print_stack(st);
	
	del_shape(sh3);
	del_shape(sh2);
	del_shape(sh1);
	del_object(ob2);
	del_object(ob);
	del_stack(st);
	
	return 0;
}
