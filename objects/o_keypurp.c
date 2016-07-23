
#include "../stack/stack.h"
#include "../state/state.h"
#include "keypurp/keypurp.h"

object push_keypurp(state *g_st){
	object ob = init_object();
	
	if(g_st->keyshape_delay < 3){
		if ( g_st->k.a )    ob = push_object(ob, keypurp_a_01());
		if ( g_st->k.d )    ob = push_object(ob, keypurp_d_01());
		if ( g_st->k.dn )   ob = push_object(ob, keypurp_down_01());
		if ( g_st->k.ent )  ob = push_object(ob, keypurp_ent_01());
		if ( g_st->k.esc )  ob = push_object(ob, keypurp_esc_01());
		if ( g_st->k.lt )   ob = push_object(ob, keypurp_left_01());
		if ( g_st->k.rt )   ob = push_object(ob, keypurp_right_01());
		if ( g_st->k.s )    ob = push_object(ob, keypurp_s_01());
		if ( g_st->k.up )   ob = push_object(ob, keypurp_up_01());
		if ( g_st->k.w )    ob = push_object(ob, keypurp_w_01());
	}else if(g_st->keyshape_delay < 6){
		if ( g_st->k.a )    ob = push_object(ob, keypurp_a_02());
		if ( g_st->k.d )    ob = push_object(ob, keypurp_d_02());
		if ( g_st->k.dn )   ob = push_object(ob, keypurp_down_02());
		if ( g_st->k.ent )  ob = push_object(ob, keypurp_ent_02());
		if ( g_st->k.esc )  ob = push_object(ob, keypurp_esc_02());
		if ( g_st->k.lt )   ob = push_object(ob, keypurp_left_02());
		if ( g_st->k.rt )   ob = push_object(ob, keypurp_right_02());
		if ( g_st->k.s )    ob = push_object(ob, keypurp_s_02());
		if ( g_st->k.up )   ob = push_object(ob, keypurp_up_02());
		if ( g_st->k.w )    ob = push_object(ob, keypurp_w_02());
	}else if(g_st->keyshape_delay < 9){
		if ( g_st->k.a )    ob = push_object(ob, keypurp_a_03());
		if ( g_st->k.d )    ob = push_object(ob, keypurp_d_03());
		if ( g_st->k.dn )   ob = push_object(ob, keypurp_down_03());
		if ( g_st->k.ent )  ob = push_object(ob, keypurp_ent_03());
		if ( g_st->k.esc )  ob = push_object(ob, keypurp_esc_03());
		if ( g_st->k.lt )   ob = push_object(ob, keypurp_left_03());
		if ( g_st->k.rt )   ob = push_object(ob, keypurp_right_03());
		if ( g_st->k.s )    ob = push_object(ob, keypurp_s_03());
		if ( g_st->k.up )   ob = push_object(ob, keypurp_up_03());
		if ( g_st->k.w )    ob = push_object(ob, keypurp_w_03());
	}
	
	ob.z = 0;
	
	return ob;
}
