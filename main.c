
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "state/state.h"
#include "objects/o_keywholes.h"
#include "objects/o_keypurp.h"
#include "sdl/draw.h"
#include "sdl/swindow.h"

#include <unistd.h>

const int SCREEN_TICKS_PER_FRAME = 1000 / 60;

struct Timer{
	int startTicks;
	int pausedTicks;
};
typedef struct Timer timer;

int main(){
	
	swindow g_swindow = init_swindow(g_swindow);
	
	if(init_sdl(&g_swindow) == 1)
		g_swindow.quit = 1;
		
	state g_state = init_state();
	
	timer fpsTimer = { .startTicks = 0, .pausedTicks = 0};
	timer capTimer = { .startTicks = 0, .pausedTicks = 0};
	int countedFrames = 0;
	fpsTimer.startTicks = SDL_GetTicks();
	
	while( !g_swindow.quit ){
		capTimer.startTicks = SDL_GetTicks();
				
		stack g_stack = init_stack();
		
		float avgFPS = countedFrames / ((SDL_GetTicks() - fpsTimer.startTicks) / 1000.0 );
		if( avgFPS > 2000000 )
		{
			avgFPS = 0;
		}
		printf("avg: %f\n", avgFPS);
		
		parse_event(&g_swindow.e, &g_swindow, &g_state);
		
		g_stack = push_stack(g_stack, push_keypurp(&g_state));
		g_stack = push_stack(g_stack, push_keywhole(&g_state));
		
		g_swindow.renderer = draw_stack(g_stack, g_swindow.renderer, g_swindow.r);
		
		del_stack(g_stack);
		
		SDL_RenderPresent( g_swindow.renderer );
		countedFrames++;
		
		if ((SDL_GetTicks() - capTimer.startTicks) < SCREEN_TICKS_PER_FRAME )
			SDL_Delay(SCREEN_TICKS_PER_FRAME - (SDL_GetTicks() - capTimer.startTicks));
	}
	
	SDL_DestroyWindow(g_swindow.window);
	SDL_DestroyRenderer(g_swindow.renderer);
	SDL_Quit();
	
	return 0;
}
