
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "draw.h"
#include "../stack/stack.h"

SDL_Renderer* draw_shape(shape drsh, SDL_Renderer* renderer, float r){
	
	if (r != 1.0){
		int i;
		for(i = 0; i < drsh.points; i++){
			drsh.x[i] = (float)drsh.x[i] * r;
			drsh.y[i] = (float)drsh.y[i] * r;
		}
	}
	
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

SDL_Renderer* draw_stack(stack drs, SDL_Renderer* renderer, float r){
	
	SDL_SetRenderDrawColor( renderer, 0x00, 0x00, 0x00, 0x00 );
	SDL_RenderClear( renderer );
	
	while(drs.top >= 0){
		while(drs.stk[drs.top].top >= 0){
			object *top_object = &drs.stk[drs.top];
			draw_shape(top_object->shp[top_object->top], renderer, r);
			*top_object = pop_object(*top_object);
		}
		drs = pop_stack(drs);
	}
	
	return renderer;
}
