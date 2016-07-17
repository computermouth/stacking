
#include "../stack.h"
#include "red/red.h"

object push_red(){
	object ob = init_object();
	
	ob = push_object(ob, red());
	
	ob.z = -1;
	
	return ob;
}
