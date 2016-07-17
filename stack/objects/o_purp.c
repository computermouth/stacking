
#include "../stack.h"
#include "purp/purp.h"

object push_purp(){
	object ob = init_object();
	
	ob = push_object(ob, purp());
	
	ob.z = 9;
	
	return ob;
}
