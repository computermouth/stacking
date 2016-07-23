
#ifndef _SWINDOW_H_
#define _SWINDOW_H_

#include <SDL2/SDL.h>
#include "../state/state.h"

struct Swindow{
	SDL_Window*		window;
	SDL_Renderer*	renderer;
	SDL_Event		e;
	int 			d_w;
	int 			d_h;
	int 			n_w;
	int 			n_h;
	int				focus;
	int				fs;
	int				min;
	int 			quit;
};
typedef struct Swindow swindow;

swindow init_swindow(swindow);
int init_sdl(swindow *);
void window_event(SDL_Event *, swindow *);
void key_event(SDL_Event *, state *);
void clear_keys(state *);
void parse_event(SDL_Event *, swindow *, state *);

#endif
