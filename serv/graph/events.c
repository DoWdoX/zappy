/*
** EPITECH PROJECT, 2018
** envents.c
** File description:
** 
*/

#include "graphical.h"

static void	mouse_events(graph_t *g, int width, int height)
{
	int x = 0;
	int y = 0;

	SDL_PumpEvents();
	if (SDL_BUTTON(SDL_BUTTON_LEFT) && SDL_GetMouseState(&x, &y)) {
		x = (x - x % TILE_SIZE) / TILE_SIZE - 2;
		y = (y - y % TILE_SIZE) / TILE_SIZE - 2;
		if (x >= 0 && x < width && y >= 0 && y < height) {
			g->x_detail = x;
			g->y_detail = y;
		}
	}
}

int	events_handling(graph_t *g, int width, int height)
{
	SDL_PollEvent(&g->event);
	mouse_events(g, width, height);
	if (g->event.type == SDL_KEYDOWN) {
		switch (g->event.key.keysym.sym) {
		case SDLK_ESCAPE:
			return (-1);
		case SDLK_f:
			Mix_PlayChannel( -1, g->screams[0], 0 );
		case SDLK_d:
			Mix_PlayChannel( -1, g->screams[1], 0 );
		case SDLK_t:
			Mix_PlayChannel( -1, g->screams[2], 0 );
		case SDLK_p:
			Mix_PlayChannel( -1, g->screams[3], 0 );
		default:
			return (0);
		}
	}
	return (0);
}
