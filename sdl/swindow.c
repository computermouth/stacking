
#include "swindow.h"

swindow init_swindow( swindow g_swindow ){
	g_swindow.window	= 0;
	g_swindow.renderer	= 0;
	g_swindow.d_w		= 800;
	g_swindow.d_h		= 500;
	g_swindow.n_w		= g_swindow.d_w;
	g_swindow.n_h		= g_swindow.d_h;
	g_swindow.r			= 1.0;
	g_swindow.p_x		= 0;
	g_swindow.p_y		= 0;
	g_swindow.focus		= 1;
	g_swindow.fs		= 0;
	g_swindow.min		= 0;
	g_swindow.quit 		= 0;
	
	return g_swindow;
}

int init_sdl(swindow *g_swindow){
	
	if(SDL_Init(SDL_INIT_EVERYTHING) >= 0){
		g_swindow->window = SDL_CreateWindow("Stacking",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
			g_swindow->n_w, g_swindow->n_h, 
			SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		
		if(g_swindow->window != 0){
			g_swindow->renderer = SDL_CreateRenderer(g_swindow->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}else{
			return 1;
		}
	}else{
		return 1;
	}
	
	return 0;
}

void window_event(SDL_Event *e, swindow *g_swindow){
	const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
	if( e->type == SDL_WINDOWEVENT )
	{
		switch( e->window.event )
		{
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				g_swindow->n_w = e->window.data1;
				g_swindow->n_h = e->window.data2;
								
				if(((float)g_swindow->n_w / (float)g_swindow->d_w) >= 
					((float)g_swindow->n_w / (float)g_swindow->d_w)){
					g_swindow->r = ((float)g_swindow->n_w / (float)g_swindow->d_w);
					g_swindow->p_x	= 0;
					g_swindow->p_y	= 0;
				}else{
					g_swindow->r = ((float)g_swindow->n_h / (float)g_swindow->d_h);
					g_swindow->p_x	= 0;
					g_swindow->p_y	= 0;
				}
				
				SDL_RenderPresent( g_swindow->renderer );
				break;
				
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				g_swindow->focus = 1;
				break;

			case SDL_WINDOWEVENT_FOCUS_LOST:
				g_swindow->focus = 0;
				break;

			case SDL_WINDOWEVENT_MINIMIZED:
				g_swindow->min = 1;
				break;

			case SDL_WINDOWEVENT_MAXIMIZED:
				g_swindow->min = 0;
				break;
			
			case SDL_WINDOWEVENT_RESTORED:
				g_swindow->min = 0;
				break;
		}
	}
	if( e->type == SDL_KEYDOWN ){
		if( ((currentKeyStates[SDL_SCANCODE_RETURN]) && 
		((currentKeyStates[SDL_SCANCODE_RALT]) || 
		(currentKeyStates[SDL_SCANCODE_LALT]))) ){
			if( g_swindow->fs ){
				SDL_SetWindowFullscreen( g_swindow->window, SDL_FALSE );
				g_swindow->fs = 0;
			}else{
				SDL_SetWindowFullscreen( g_swindow->window, SDL_WINDOW_FULLSCREEN_DESKTOP );
				g_swindow->fs = 1;
			}
		}else if (currentKeyStates[SDL_SCANCODE_RETURN]){
			
		}
	}
}

void key_event(SDL_Event *e, state *g_state){
	
	if( e->type == SDL_KEYDOWN ){
		switch(e->key.keysym.sym){
			case SDLK_ESCAPE:
				g_state->k.esc = 1;
				break;
			case SDLK_RETURN:
				g_state->k.ent = 1;
				break;
			case SDLK_UP:
				g_state->k.up = 1;
				break;
			case SDLK_DOWN:
				g_state->k.dn = 1;
				break;
			case SDLK_LEFT:
				g_state->k.lt = 1;
				break;
			case SDLK_RIGHT:
				g_state->k.rt = 1;
				break;
			case SDLK_w:
				g_state->k.w = 1;
				break;
			case SDLK_a:
				g_state->k.a = 1;
				break;
			case SDLK_s:
				g_state->k.s = 1;
				break;
			case SDLK_d:
				g_state->k.d = 1;
				break;
		}
	} else if ( e->type == SDL_KEYUP) {
		switch(e->key.keysym.sym){
			case SDLK_ESCAPE:
				g_state->k.esc = 0;
				break;
			case SDLK_RETURN:
				g_state->k.ent = 0;
				break;
			case SDLK_UP:
				g_state->k.up = 0;
				break;
			case SDLK_DOWN:
				g_state->k.dn = 0;
				break;
			case SDLK_LEFT:
				g_state->k.lt = 0;
				break;
			case SDLK_RIGHT:
				g_state->k.rt = 0;
				break;
			case SDLK_w:
				g_state->k.w = 0;
				break;
			case SDLK_a:
				g_state->k.a = 0;
				break;
			case SDLK_s:
				g_state->k.s = 0;
				break;
			case SDLK_d:
				g_state->k.d = 0;
				break;
		}
	}
}

void clear_keys(state *g_state){
	g_state->k.esc = 0;
	g_state->k.ent = 0;
	g_state->k.w = 0;
	g_state->k.a = 0;
	g_state->k.s = 0;
	g_state->k.d = 0;
	g_state->k.up = 0;
	g_state->k.dn = 0;
	g_state->k.lt = 0;
	g_state->k.rt = 0;
}

void parse_event(SDL_Event *e, swindow *g_swindow, state *g_state){
	
	while( SDL_PollEvent( e )){
		switch(e->type){
			case SDL_QUIT:
				g_swindow->quit++;
				break;
			default:
				window_event(e , g_swindow);
				key_event(e , g_state);
				break;
		}
	}
	

}
