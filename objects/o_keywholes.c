
#include "../stack/stack.h"
#include "../state/state.h"
#include "keywholes/whole.h"

object push_keywhole(state *g_st){
	object ob = init_object();
	
	if(g_st->keyshape_delay < 3){
		ob = push_object(ob, whole_a_01());
		ob = push_object(ob, whole_d_01());
		ob = push_object(ob, whole_down_01());
		ob = push_object(ob, whole_ent_01());
		ob = push_object(ob, whole_esc_01());
		ob = push_object(ob, whole_left_01());
		ob = push_object(ob, whole_right_01());
		ob = push_object(ob, whole_s_01());
		ob = push_object(ob, whole_up_01());
		ob = push_object(ob, whole_w_01());
	}else if(g_st->keyshape_delay < 6){
		ob = push_object(ob, whole_a_02());
		ob = push_object(ob, whole_d_02());
		ob = push_object(ob, whole_down_02());
		ob = push_object(ob, whole_ent_02());
		ob = push_object(ob, whole_esc_02());
		ob = push_object(ob, whole_left_02());
		ob = push_object(ob, whole_right_02());
		ob = push_object(ob, whole_s_02());
		ob = push_object(ob, whole_up_02());
		ob = push_object(ob, whole_w_02());
	}else if(g_st->keyshape_delay < 9){
		ob = push_object(ob, whole_a_03());
		ob = push_object(ob, whole_d_03());
		ob = push_object(ob, whole_down_03());
		ob = push_object(ob, whole_ent_03());
		ob = push_object(ob, whole_esc_03());
		ob = push_object(ob, whole_left_03());
		ob = push_object(ob, whole_right_03());
		ob = push_object(ob, whole_s_03());
		ob = push_object(ob, whole_up_03());
		ob = push_object(ob, whole_w_03());
	}
	
	g_st->keyshape_delay++;
	g_st->keyshape_delay = g_st->keyshape_delay%9;
	
	ob.z = 1;
	
	return ob;
}
