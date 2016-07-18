
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "stack/objects/o_bleen.h"
#include "stack/objects/o_purp.h"
#include "stack/objects/o_red.h"

#include "sdl/draw.h"

SDL_Window*		window			= 0;
SDL_Renderer*	renderer		= 0;
const int 		SCREEN_WIDTH	= 480;
const int 		SCREEN_HEIGHT	= 272;

int init_sdl(){
	
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		window = SDL_CreateWindow("Stacking",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			SCREEN_WIDTH, SCREEN_HEIGHT, 
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		
		if(window != 0){
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}else{
			return 1;
		}
	}else{
		return 1;
	}
	
	return 0;
}

int main(){
	
	if(init_sdl() == 1)
		return 1;
	
	stack st = init_stack();
	
	st = push_stack(st, push_bleen());
	st = push_stack(st, push_purp());
	st = push_stack(st, push_red());

	//print_stack(st);
	renderer = draw_stack(st, renderer);

	del_stack(st);
	
	SDL_RenderPresent( renderer );
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	return 0;
}
