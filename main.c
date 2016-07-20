
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
//~ #include "stack/objects/o_bleen.h"
//~ #include "stack/objects/o_purp.h"
//~ #include "stack/objects/o_red.h"

#include "stack/objects/o_keywholes.h"

#include "sdl/draw.h"
#include "sdl/swindow.h"

#include <unistd.h>

//~ enum Some { ONE, TWO , THREE};
//~ typedef enum Some some;

int main(){
	
	swindow sw = init_swindow(sw);
	
	if(init_sdl(&sw) == 1)
		return 1;
		
	int i = 0;
	
	while( !sw.quit ){
		parse_event(&sw.e, &sw);
		
		stack st = init_stack();
		
		st = push_stack(st, push_keywhole(i));
		if (i < 2)
			i++;
		else
			i = 0;
		
		//print_stack(st);
		sw.renderer = draw_stack(st, sw.renderer);
		
		del_stack(st);
		
		SDL_RenderPresent( sw.renderer );
		
		usleep(162.5*1000);
		
	}
	
	SDL_DestroyWindow(sw.window);
	SDL_DestroyRenderer(sw.renderer);
	SDL_Quit();
	
	return 0;
}
