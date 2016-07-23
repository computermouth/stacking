
#include "swindow.h"

swindow init_swindow( swindow sw ){
	sw.window	= 0;
	sw.renderer	= 0;
	sw.d_w		= 800;
	sw.d_h		= 500;
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
			sw->n_w, sw->n_h, 
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
				sw->n_h = e->window.data2;
				SDL_RenderPresent( sw->renderer );
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
	if( e->type == SDL_KEYDOWN ){
		if( ((currentKeyStates[SDL_SCANCODE_RETURN]) && 
		((currentKeyStates[SDL_SCANCODE_RALT]) || 
		(currentKeyStates[SDL_SCANCODE_LALT]))) ){
			if( sw->fs ){
				SDL_SetWindowFullscreen( sw->window, SDL_FALSE );
				sw->fs = 0;
			}else{
				SDL_SetWindowFullscreen( sw->window, SDL_WINDOW_FULLSCREEN_DESKTOP );
				sw->fs = 1;
			}
		}else if (currentKeyStates[SDL_SCANCODE_RETURN]){
			
		}
	}
}

void key_event(SDL_Event *e, state *g_st){
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

	if( e->type == SDL_KEYDOWN ){
		if(currentKeyStates[SDL_SCANCODE_ESCAPE])
			g_st->k.esc = 1;
		if(currentKeyStates[SDL_SCANCODE_RETURN])
			g_st->k.ent = 1;
		if(currentKeyStates[SDL_SCANCODE_W])
			g_st->k.w = 1;
		if(currentKeyStates[SDL_SCANCODE_A])
			g_st->k.a = 1;
		if(currentKeyStates[SDL_SCANCODE_S])
			g_st->k.w = 1;
		if(currentKeyStates[SDL_SCANCODE_D])
			g_st->k.d = 1;
		if(currentKeyStates[SDL_SCANCODE_UP])
			g_st->k.up = 1;
		if(currentKeyStates[SDL_SCANCODE_DOWN])
			g_st->k.dn = 1;
		if(currentKeyStates[SDL_SCANCODE_LEFT])
			g_st->k.lt = 1;
		if(currentKeyStates[SDL_SCANCODE_RIGHT])
			g_st->k.rt = 1;
	}
}

void clear_keys(state *g_st){
	g_st->k.esc = 0;
	g_st->k.ent = 0;
	g_st->k.w = 0;
	g_st->k.a = 0;
	g_st->k.w = 0;
	g_st->k.d = 0;
	g_st->k.up = 0;
	g_st->k.dn = 0;
	g_st->k.lt = 0;
	g_st->k.rt = 0;
}

void parse_event(SDL_Event *e, swindow *sw, state *g_st){
	
	while( SDL_PollEvent( e ) != 0 ){
		switch(e->type){
			case SDL_QUIT:
				sw->quit++;
			break;
		}
	}
	
	window_event(e , sw);
	key_event(e , g_st);
}
