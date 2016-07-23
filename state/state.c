
#include "state.h"

state init_state(){
	state sta;
	
	sta.k.esc = 0;
	sta.k.ent = 0;
    sta.k.w = 0;
    sta.k.a = 0;
    sta.k.s = 0;
    sta.k.d = 0;
    sta.k.up = 0;
    sta.k.dn = 0;
    sta.k.lt = 0;
    sta.k.rt = 0;
    
    sta.keyshape_delay = 0;
	sta.keywhole_stg = 0;
	sta.keypurp_stg = 1;

	return sta;
}
