
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "draw.h"
#include "../stack/stack.h"

SDL_Renderer* draw_shape(shape drsh, SDL_Renderer* renderer){
	
	filledPolygonRGBA(renderer, 
		drsh.x, 
		drsh.y,
		drsh.points,
		drsh.color[0], 
		drsh.color[1], 
		drsh.color[2], 
		drsh.color[3]);
	
	return renderer;
}

SDL_Renderer* draw_stack(stack drs, SDL_Renderer* renderer){
	
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear( renderer );
	
	while(drs.top >= 0){
		while(drs.stk[drs.top].top >= 0){
			draw_shape(drs.stk[drs.top].shp[drs.stk[drs.top].top], renderer);
			drs.stk[drs.top] = pop_object(drs.stk[drs.top]);
		}
		drs = pop_stack(drs);
	}
	
	return renderer;
}
