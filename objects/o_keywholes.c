
#include "../stack/stack.h"
#include "../state/state.h"
#include "o_keywholes.h"
#include "keywholes/whole.h"

o_whole init_o_whole(){
	o_whole g_o_whole;
	
	g_o_whole.o_whole_01 = init_whole_01();
    g_o_whole.o_whole_02 = init_whole_02();
	g_o_whole.o_whole_03 = init_whole_03();
	
	return g_o_whole;
}

void del_o_whole(o_whole g_o_whole){
	del_whole_01(g_o_whole.o_whole_01);
	del_whole_02(g_o_whole.o_whole_02);
	del_whole_03(g_o_whole.o_whole_03);
}

object push_keywhole(state *g_state, o_whole g_o_whole){
	object g_object = init_object();
	
	if(g_state->keyshape_delay < 3){
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_a_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_d_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_down_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_ent_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_esc_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_left_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_right_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_s_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_up_01);
		g_object = push_object(g_object, g_o_whole.o_whole_01.whole_w_01);
	}else if(g_state->keyshape_delay < 6){
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_a_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_d_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_down_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_ent_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_esc_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_left_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_right_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_s_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_up_02);
		g_object = push_object(g_object, g_o_whole.o_whole_02.whole_w_02);
	}else if(g_state->keyshape_delay < 9){
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_a_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_d_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_down_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_ent_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_esc_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_left_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_right_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_s_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_up_03);
		g_object = push_object(g_object, g_o_whole.o_whole_03.whole_w_03);
	}
	
	g_state->keyshape_delay++;
	g_state->keyshape_delay = g_state->keyshape_delay%9;
	
	g_object.z = 1;
	
	return g_object;
}
