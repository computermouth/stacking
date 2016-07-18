
#include <stdio.h>
#include "stack/stack.h"
#include "stack/objects/o_bleen.h"
#include "stack/objects/o_purp.h"
#include "stack/objects/o_red.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

SDL_Window*		window			= 0;
SDL_Renderer*	renderer		= 0;
const int 		SCREEN_WIDTH	= 800;
const int 		SCREEN_HEIGHT	= 500;

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

void draw_shape(shape drsh){
	
	filledPolygonRGBA(renderer, 
		drsh.x, 
		drsh.y,
		drsh.points,
		drsh.color[0], 
		drsh.color[1], 
		drsh.color[2], 
		drsh.color[3]);
}

void draw_stack(stack drs){
	
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear( renderer );
	
	while(drs.top >= 0){
		while(drs.stk[drs.top].top >= 0){
			draw_shape(drs.stk[drs.top].shp[drs.stk[drs.top].top]);
			drs.stk[drs.top] = pop_object(drs.stk[drs.top]);
		}
		drs = pop_stack(drs);
	}
}

int main(){
	
	int i = init_sdl();
	if(i == 1)
		return 1;
	
	for(i = 0; i < 500; i++){
		stack st = init_stack();
		
		st = push_stack(st, push_bleen());
		st = push_stack(st, push_purp());
		st = push_stack(st, push_red());

		//print_stack(st);
		draw_stack(st);

		del_stack(st);
		
		SDL_RenderPresent( renderer );
	}
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	return 0;
}
