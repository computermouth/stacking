
#include <stdio.h>
#include "stack/stack.h"
#include "stack/objects/o_bleen.h"
#include "stack/objects/o_purp.h"
#include "stack/objects/o_red.h"

int main(){
	int i;
	for(i = 0; i < 3000; i++){
		
		stack st = init_stack();

		st = push_stack(st, push_bleen());
		st = push_stack(st, push_purp());
		st = push_stack(st, push_red());

		//print_stack(st);
		
		del_stack(st);
	}
	
	return 0;
}
