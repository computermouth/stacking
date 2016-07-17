
#include <stdio.h>

#include "stack.h"

int main(){
	stack st = init_stack();

	object ob = init_object();
	object ob2 = init_object();
	object ob3 = init_object();
	
	short x[] = {100, 400, 400, 100};
	short y[] = {100, 100, 400, 400};
	short points = 4;
	short color[] = {0, 255, 0, 255};
	short z = 5;
	
	shape sh1 = init_shape(x, y, points, color, z);
	ob = push_object(ob, sh1);
	ob.z = 9;
	
	short x2[] = {200, 500, 500, 200};
	short y2[] = {500, 500, 200, 200};
	short points2 = 4;
	short color2[] = {255, 0, 0, 255};
	short z2 = 2;
	
	shape sh2 = init_shape(x2, y2, points2, color2, z2);
	ob = push_object(ob, sh2);
	
	short x3[] = {300, 600, 600, 300};
	short y3[] = {600, 600, 300, 300};
	short points3 = 4;
	short color3[] = {0, 0, 255, 255};
	short z3 = 7;
	
	shape sh3 = init_shape(x3, y3, points3, color3, z3);
	ob2 = push_object(ob2, sh3);
	ob2.z = 1;
	
	short x4[] = {300, 600, 600, 300};
	short y4[] = {600, 600, 300, 300};
	short points4 = 4;
	short color4[] = {0, 0, 255, 255};
	short z4 = 11;
	
	shape sh4 = init_shape(x4, y4, points4, color4, z4);
	ob3 = push_object(ob3, sh4);
	ob3.z = -11;
	
	st = push_stack(st, ob);
	st = push_stack(st, ob2);
	st = push_stack(st, ob3);
	
	print_stack(st);
	
	del_shape(sh4);
	del_shape(sh3);
	del_shape(sh2);
	del_shape(sh1);
	del_object(ob3);
	del_object(ob2);
	del_object(ob);
	del_stack(st);
	
	return 0;
}
