
#include <stdio.h>
#include "stack/stack.h"
#include "stack/objects/o_bleen.h"

int main(){
	stack st = init_stack();

	//~ object ob = init_object();
	//~ object ob2 = init_object();
	//~ object ob3 = init_object();
	

	//~ ob = push_object(ob, sh1);
	//~ ob.z = 9;
	

	//~ ob = push_object(ob, sh2);
	

	//~ ob2 = push_object(ob2, sh3);
	//~ ob2.z = 1;
	

	//~ ob3 = push_object(ob3, sh4);
	//~ ob3.z = -11;
	
	st = push_stack(st, push_bleen());
	//~ st = push_stack(st, ob2);
	//~ st = push_stack(st, ob3);
	
	print_stack(st);
	
	//~ del_shape(sh4);
	//~ del_shape(sh3);
	//~ del_shape(sh2);
	//~ del_shape(sh1);
	//~ del_object(ob3);
	//~ del_object(ob2);
	//~ del_object(ob);
	del_stack(st);
	
	return 0;
}
