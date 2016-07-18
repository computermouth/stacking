
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "stack/objects/o_bleen.h"
#include "stack/objects/o_purp.h"
#include "stack/objects/o_red.h"

#include "sdl/draw.h"

SDL_Window*		window			= 0;
SDL_Renderer*	renderer		= 0;
SDL_Event		e;
const int 		SCREEN_WIDTH	= 480;
const int 		SCREEN_HEIGHT	= 272;
int quit = 0;

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

void window_event(SDL_Event *e){
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	//Window event occured
	if( e->type == SDL_WINDOWEVENT )
	{
		switch( e->window.event )
		{
			//Get new dimensions and repaint on window size change
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			//~ mWidth = e.window.data1;
			//~ mHeight = e.window.data2;
			SDL_RenderPresent( renderer );
			break;

			//Repaint on exposure
			case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent( renderer );
			break;

			//Window has keyboard focus
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			//~ mKeyboardFocus = true;
			//~ updateCaption = true;
			break;

			//Window lost keyboard focus
			case SDL_WINDOWEVENT_FOCUS_LOST:
			//~ mKeyboardFocus = false;
			//~ updateCaption = true;
			break;

			//Window minimized
			case SDL_WINDOWEVENT_MINIMIZED:
            //~ mMinimized = true;
            break;

			//Window maxized
			case SDL_WINDOWEVENT_MAXIMIZED:
			//~ mMinimized = false;
            break;
			
			//Window restored
			case SDL_WINDOWEVENT_RESTORED:
			//~ mMinimized = false;
            break;
		}
	}
	//Enter exit full screen on return key
	else if( e->type == SDL_KEYDOWN && ((currentKeyStates[SDL_SCANCODE_RETURN]) && ((currentKeyStates[SDL_SCANCODE_RALT]) || (currentKeyStates[SDL_SCANCODE_LALT]))))
	{
		//~ if( mFullScreen )
		//~ {
			//~ SDL_SetWindowFullscreen( mWindow, SDL_FALSE );
			//~ mFullScreen = false;
		//~ }
		//~ else
		//~ {
			//~ SDL_SetWindowFullscreen( mWindow, SDL_TRUE );
			//~ mFullScreen = true;
			//~ mMinimized = false;
		//~ }
	}
}

void parse_event(SDL_Event *e){
	
	while( SDL_PollEvent( e ) != 0 ){
		switch(e->type){
			case SDL_QUIT:
				quit++;
			break;
		}
	}
	
	window_event( e );
}

int main(){
	
	if(init_sdl() == 1)
		return 1;
	
	while( !quit ){
		parse_event(&e);
		
		stack st = init_stack();
		
		st = push_stack(st, push_bleen());
		st = push_stack(st, push_purp());
		st = push_stack(st, push_red());

		//print_stack(st);
		renderer = draw_stack(st, renderer);

		del_stack(st);
		
		SDL_RenderPresent( renderer );
		
	}
	
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
	return 0;
}
