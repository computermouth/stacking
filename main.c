
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "state/state.h"
#include "objects/o_keywholes.h"
#include "objects/o_keypurp.h"
#include "sdl/draw.h"
#include "sdl/swindow.h"

int main(){
	
	swindow g_swindow = init_swindow(g_swindow);
	
	if(init_sdl(&g_swindow) == 1)
		g_swindow.quit = 1;
		
	state g_state = init_state();
	
	o_whole g_o_whole = init_o_whole();
	
	while( !g_swindow.quit ){		
		stack g_stack = init_stack();
		
		parse_event(&g_swindow.e, &g_swindow, &g_state);
		
		//~ g_stack = push_stack(g_stack, push_keypurp(&g_state));
		g_stack = push_stack(g_stack, push_keywhole(&g_state, g_o_whole));
		
		g_swindow.renderer = draw_stack(g_stack, g_swindow.renderer, g_swindow.r);
		
		del_stack(g_stack);
		
		SDL_RenderPresent( g_swindow.renderer );
	}
	
	del_o_whole(g_o_whole);
	
	SDL_DestroyWindow(g_swindow.window);
	SDL_DestroyRenderer(g_swindow.renderer);
	SDL_Quit();
	
	return 0;
}
