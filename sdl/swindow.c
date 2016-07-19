
#include "swindow.h"

swindow init_swindow( swindow sw ){
	sw.window	= 0;
	sw.renderer	= 0;
	sw.d_w		= 480;
	sw.d_h		= 272;
	sw.n_w		= sw.d_w;
	sw.n_h		= sw.d_h;
	sw.focus	= 1;
	sw.fs		= 0;
	sw.min		= 0;
	sw.quit 	= 0;
	
	return sw;
}

int init_sdl(swindow *sw){
	
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		sw->window = SDL_CreateWindow("Stacking",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			sw->d_w, sw->d_h, 
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
	if( e->type == SDL_WINDOWEVENT )
	{
		switch( e->window.event )
		{
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				sw->n_w = e->window.data1;
				sw->n_w = e->window.data2;
				break;

			case SDL_WINDOWEVENT_FOCUS_GAINED:
				sw->focus = 1;
				break;

			case SDL_WINDOWEVENT_FOCUS_LOST:
				sw->focus = 0;
				break;

			case SDL_WINDOWEVENT_MINIMIZED:
				sw->min = 1;
				break;

			case SDL_WINDOWEVENT_MAXIMIZED:
				sw->min = 0;
				break;
			
			case SDL_WINDOWEVENT_RESTORED:
				sw->min = 0;
				break;
		}
	}
	else if( e->type == SDL_KEYDOWN && 
		((currentKeyStates[SDL_SCANCODE_RETURN]) && 
		((currentKeyStates[SDL_SCANCODE_RALT]) || 
		(currentKeyStates[SDL_SCANCODE_LALT]))))
	{
		if( sw->fs ){
			SDL_SetWindowFullscreen( sw->window, SDL_FALSE );
			sw->fs = 0;
		}else{
			SDL_SetWindowFullscreen( sw->window, SDL_TRUE );
			sw->fs = 1;
			sw->min = 0;
		}
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
