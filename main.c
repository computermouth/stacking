
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "stack/objects/o_bleen.h"
#include "stack/objects/o_purp.h"
#include "stack/objects/o_red.h"

#include "sdl/draw.h"
#include "sdl/swindow.h"

int main(){
	
	swindow sw = init_swindow(sw);
	
	if(init_sdl(&sw) == 1)
		return 1;
	
	while( !sw.quit ){
		parse_event(&sw.e, &sw);
		
		stack st = init_stack();
		
		st = push_stack(st, push_bleen());
		st = push_stack(st, push_purp());
		st = push_stack(st, push_red());

		//print_stack(st);
		sw.renderer = draw_stack(st, sw.renderer);

		del_stack(st);
		
		SDL_RenderPresent( sw.renderer );
		
	}
	
	SDL_DestroyWindow(sw.window);
	SDL_DestroyRenderer(sw.renderer);
	SDL_Quit();
	
	return 0;
}
