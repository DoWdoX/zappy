/*
** EPITECH PROJECT, 2018
** init_graph.c
** File description:
** 
*/

#include "graphical.h"
#include "serv.h"
#include <SDL/SDL_ttf.h>

void	apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect offset;

	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}

Mix_Chunk	**init_screams(void)
{
	Mix_Chunk **r = malloc(sizeof(Mix_Chunk *) * 4);
	int i = 0;

	r[i++] = Mix_LoadWAV(PATH_EGG_P03);
	r[i++] = Mix_LoadWAV(PATH_EGG_P06);
	r[i++] = Mix_LoadWAV(PATH_EGG_P09);
	r[i++] = Mix_LoadWAV(PATH_EGG_P25);
	return (r);
}

SDL_Surface	**init_balls(void)
{
	SDL_Surface **new = malloc(sizeof(SDL_Surface *) * 6);

	new[0] = load_image_png(PATH_LINEMATE);
	new[1] = load_image_png(PATH_DERAUMERE);
	new[2] = load_image_png(PATH_SIBUR);
	new[3] = load_image_png(PATH_MENDIANE);
	new[4] = load_image_png(PATH_PHIRAS);
	new[5] = load_image_png(PATH_THYSTAM);
	return (new);
}

static SDL_Surface	**init_badges()
{
	SDL_Surface **new = malloc(sizeof(SDL_Surface *) * 9);

	new[0] = NULL;
	new[1] = load_image_png(PATH_BADGE_1);
	new[2] = load_image_png(PATH_BADGE_2);
	new[3] = load_image_png(PATH_BADGE_3);
	new[4] = load_image_png(PATH_BADGE_4);
	new[5] = load_image_png(PATH_BADGE_5);
	new[6] = load_image_png(PATH_BADGE_6);
	new[7] = load_image_png(PATH_BADGE_7);
	new[8] = load_image_png(PATH_BADGE_8);
	return (new);
}

static void	init_g(graph_t *g)
{
	g->music = Mix_LoadMUS(PATH_SONG);
	g->screams = init_screams();
	g->balls = init_balls();
	g->food = load_image_png(PATH_FOOD);
	g->smap = load_map_ressources();
	g->ttlfont = TTF_OpenFont(PATH_FONT, 20);
	g->coordfont = TTF_OpenFont(PATH_FONT, 17);
	g->basefont = TTF_OpenFont(PATH_FONT, 14);
	g->color.r = 255;
	g->color.g = 255;
	g->color.b = 255;
	g->mainbox = load_image_png(PATH_MAINBOX);
        g->badges = init_badges();
	g->mark = load_image_png(PATH_MARK);
	g->x_detail = -1;
	g->y_detail = -1;
	g->selected = -1;
}

graph_t	*init_graph(gmap_t *map)
{
	graph_t *g = malloc(sizeof(graph_t));
	int scr_w = SCREEN_WIDTH(map->width);
	int scr_h = SCREEN_HEIGHT(map->height);

	if (scr_h < 720)
		scr_h = 720;
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	g->screen = SDL_SetVideoMode(scr_w, scr_h, SCREEN_BPP, SDL_HWSURFACE);
	SDL_WM_SetCaption("Pokemon version Zappy", NULL);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	init_g(g);
	Mix_PlayMusic(g->music, -1);
	return (g);
}

void	destroy_graph(graph_t *g)
{
	SDL_FreeSurface(g->screen);
	Mix_FreeMusic(g->music);
	Mix_FreeChunk(g->screams[0]);
	Mix_FreeChunk(g->screams[1]);
	Mix_FreeChunk(g->screams[2]);
	Mix_FreeChunk(g->screams[3]);
	free(g);
	TTF_Quit();
	SDL_Quit();
}
