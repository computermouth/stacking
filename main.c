
#include <stdio.h>
#include <SDL2/SDL.h>

#include "stack/stack.h"
#include "stack/objects/o_bleen.h"
#include "stack/objects/o_purp.h"
#include "stack/objects/o_red.h"

#include "sdl/draw.h"

struct Swindow{
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	SDL_Event		e;
	int 			w;
	int 			h;
	int 			quit;
};
typedef struct Swindow swindow;

swindow init_swindow( swindow sw ){
	sw.window			= 0;
	sw.renderer			= 0;
	sw.w				= 480;
	sw.h				= 272;
	sw.quit 			= 0;
	
	return sw;
}

int init_sdl(swindow *sw){
	
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		sw->window = SDL_CreateWindow("Stacking",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			sw->w, sw->h, 
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		
		if(sw->window != 0){
			sw->renderer = SDL_CreateRenderer(sw->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}else{
			return 1;
		}
	}else{
		return 1;
	}
	
	return 0;
}

void window_event(SDL_Event *e, swindow *sw){
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
			SDL_RenderPresent( sw->renderer );
			break;

			//Repaint on exposure
			case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent( sw->renderer );
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

void parse_event(SDL_Event *e, swindow *sw){
	
	while( SDL_PollEvent( e ) != 0 ){
		switch(e->type){
			case SDL_QUIT:
				sw->quit++;
			break;
		}
	}
	
	window_event(e , sw);
}

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
