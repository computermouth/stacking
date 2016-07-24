
#include "../stack/stack.h"
#include "../state/state.h"
#include "keypurp/keypurp.h"

object push_keypurp(state *g_state){
	object g_object = init_object();
	
	if(g_state->keyshape_delay < 3){
		if ( g_state->k.a )    g_object = push_object(g_object, keypurp_a_01());
		if ( g_state->k.d )    g_object = push_object(g_object, keypurp_d_01());
		if ( g_state->k.dn )   g_object = push_object(g_object, keypurp_down_01());
		if ( g_state->k.ent )  g_object = push_object(g_object, keypurp_ent_01());
		if ( g_state->k.esc )  g_object = push_object(g_object, keypurp_esc_01());
		if ( g_state->k.lt )   g_object = push_object(g_object, keypurp_left_01());
		if ( g_state->k.rt )   g_object = push_object(g_object, keypurp_right_01());
		if ( g_state->k.s )    g_object = push_object(g_object, keypurp_s_01());
		if ( g_state->k.up )   g_object = push_object(g_object, keypurp_up_01());
		if ( g_state->k.w )    g_object = push_object(g_object, keypurp_w_01());
	}else if(g_state->keyshape_delay < 6){
		if ( g_state->k.a )    g_object = push_object(g_object, keypurp_a_02());
		if ( g_state->k.d )    g_object = push_object(g_object, keypurp_d_02());
		if ( g_state->k.dn )   g_object = push_object(g_object, keypurp_down_02());
		if ( g_state->k.ent )  g_object = push_object(g_object, keypurp_ent_02());
		if ( g_state->k.esc )  g_object = push_object(g_object, keypurp_esc_02());
		if ( g_state->k.lt )   g_object = push_object(g_object, keypurp_left_02());
		if ( g_state->k.rt )   g_object = push_object(g_object, keypurp_right_02());
		if ( g_state->k.s )    g_object = push_object(g_object, keypurp_s_02());
		if ( g_state->k.up )   g_object = push_object(g_object, keypurp_up_02());
		if ( g_state->k.w )    g_object = push_object(g_object, keypurp_w_02());
	}else if(g_state->keyshape_delay < 9){
		if ( g_state->k.a )    g_object = push_object(g_object, keypurp_a_03());
		if ( g_state->k.d )    g_object = push_object(g_object, keypurp_d_03());
		if ( g_state->k.dn )   g_object = push_object(g_object, keypurp_down_03());
		if ( g_state->k.ent )  g_object = push_object(g_object, keypurp_ent_03());
		if ( g_state->k.esc )  g_object = push_object(g_object, keypurp_esc_03());
		if ( g_state->k.lt )   g_object = push_object(g_object, keypurp_left_03());
		if ( g_state->k.rt )   g_object = push_object(g_object, keypurp_right_03());
		if ( g_state->k.s )    g_object = push_object(g_object, keypurp_s_03());
		if ( g_state->k.up )   g_object = push_object(g_object, keypurp_up_03());
		if ( g_state->k.w )    g_object = push_object(g_object, keypurp_w_03());
	}
	
	g_object.z = 0;
	
	return g_object;
}
