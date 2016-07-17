
#include "../stack.h"
#include "bleen/blue.h"
#include "bleen/green.h"

object push_bleen(){
	object ob = init_object();
	
	ob = push_object(ob, blue());
	ob = push_object(ob, green());
	
	ob.z = 1;
	
	return ob;
}
