
#include "../stack/stack.h"
#include "../state/state.h"
#include "keywholes/whole.h"

object push_keywhole(state *g_state){
	object g_object = init_object();
	
	if(g_state->keyshape_delay < 3){
		g_object = push_object(g_object, whole_a_01());
		g_object = push_object(g_object, whole_d_01());
		g_object = push_object(g_object, whole_down_01());
		g_object = push_object(g_object, whole_ent_01());
		g_object = push_object(g_object, whole_esc_01());
		g_object = push_object(g_object, whole_left_01());
		g_object = push_object(g_object, whole_right_01());
		g_object = push_object(g_object, whole_s_01());
		g_object = push_object(g_object, whole_up_01());
		g_object = push_object(g_object, whole_w_01());
	}else if(g_state->keyshape_delay < 6){
		g_object = push_object(g_object, whole_a_02());
		g_object = push_object(g_object, whole_d_02());
		g_object = push_object(g_object, whole_down_02());
		g_object = push_object(g_object, whole_ent_02());
		g_object = push_object(g_object, whole_esc_02());
		g_object = push_object(g_object, whole_left_02());
		g_object = push_object(g_object, whole_right_02());
		g_object = push_object(g_object, whole_s_02());
		g_object = push_object(g_object, whole_up_02());
		g_object = push_object(g_object, whole_w_02());
	}else if(g_state->keyshape_delay < 9){
		g_object = push_object(g_object, whole_a_03());
		g_object = push_object(g_object, whole_d_03());
		g_object = push_object(g_object, whole_down_03());
		g_object = push_object(g_object, whole_ent_03());
		g_object = push_object(g_object, whole_esc_03());
		g_object = push_object(g_object, whole_left_03());
		g_object = push_object(g_object, whole_right_03());
		g_object = push_object(g_object, whole_s_03());
		g_object = push_object(g_object, whole_up_03());
		g_object = push_object(g_object, whole_w_03());
	}
	
	g_state->keyshape_delay++;
	g_state->keyshape_delay = g_state->keyshape_delay%9;
	
	g_object.z = 1;
	
	return g_object;
}
