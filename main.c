
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "state/state.h"
#include "objects/o_keywholes.h"
#include "objects/o_keypurp.h"
#include "sdl/draw.h"
#include "sdl/swindow.h"

int main(){
	
	swindow sw = init_swindow(sw);
	
	if(init_sdl(&sw) == 1)
		sw.quit = 1;
		
	state g_state = init_state();
	
	while( !sw.quit ){		
		stack st = init_stack();
		
		parse_event(&sw.e, &sw, &g_state);
		
		st = push_stack(st, push_keypurp(&g_state));
		st = push_stack(st, push_keywhole(&g_state));
		
		sw.renderer = draw_stack(st, sw.renderer, sw.r);
		
		del_stack(st);
		
		SDL_RenderPresent( sw.renderer );
	}
	
	SDL_DestroyWindow(sw.window);
	SDL_DestroyRenderer(sw.renderer);
	SDL_Quit();
	
	return 0;
}
