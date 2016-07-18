
#ifndef _SWINDOW_H_
#define _SWINDOW_H_

#include <SDL2/SDL.h>

struct Swindow{
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	SDL_Event		e;
	int 			w;
	int 			h;
	int 			quit;
};
typedef struct Swindow swindow;

swindow init_swindow(swindow);
int init_sdl(swindow *);
void window_event(SDL_Event *, swindow *);
void parse_event(SDL_Event *, swindow *);

#endif
