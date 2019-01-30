/*
** EPITECH PROJECT, 2018
** print_graphk.c
** File description:
** 
*/

#include <stdlib.h>
#include "graphical.h"
#include "serv.h"

static void	apply_character(graph_t *g, characters_t *player, char *team)
{
	SDL_Surface *tmps;
	int tmpx = TILE_SIZE * player->x + START;
	int tmpy = TILE_SIZE * player->y + START;
	int pathlen = strlen(PATH_TRAINER);
	char *path = malloc(sizeof(char) * (pathlen + strlen(team) + 7));

	sprintf(path, "%s%s_%d.png", PATH_TRAINER, team, player->direction);
	tmps = load_image_png(path);
	apply_surface(tmpx, tmpy, tmps, g->screen);
}

static void	print_trainers(graph_t *g, client_t *client)
{
	client_t *tmp_cli = client;

	while (tmp_cli) {
		if (tmp_cli->alive)
			apply_character(g, tmp_cli->players, tmp_cli->team);
		tmp_cli = tmp_cli->next;
	}
}

static void	apply_ressources1(graph_t *g, map_t tile, int y, int x)
{
	int tmpx = TILE_SIZE * x + START + 4;
	int tmpy = TILE_SIZE * y + START;

	if (tile.stones.linemate)
		apply_surface(tmpx, tmpy, g->balls[0], g->screen);
	if (tile.stones.deraumere)
		apply_surface(tmpx + 14, tmpy, g->balls[1], g->screen);
	if (tile.stones.sibur)
		apply_surface(tmpx, tmpy + 8, g->balls[2], g->screen);
	if (tile.stones.mendiane)
		apply_surface(tmpx + 14, tmpy + 8, g->balls[3], g->screen);
}

static void	apply_ressources2(graph_t *g, map_t tile, int y, int x)
{
	int tmpx = TILE_SIZE * x + START + 4;
	int tmpy = TILE_SIZE * y + START;

	if (tile.stones.phiras)
		apply_surface(tmpx, tmpy + 16, g->balls[4], g->screen);
	if (tile.stones.thystam)
		apply_surface(tmpx + 14, tmpy + 16, g->balls[5], g->screen);
	if (tile.food)
		apply_surface(tmpx + 8, tmpy + 18, g->food, g->screen);
}

static void	print_ressources(graph_t *g, gmap_t *gmap, int pos)
{
	for (int y = 0; y < gmap->height; ++y) {
		for (int x = 0; x < gmap->width; ++x) {
			if (pos == 0)
				apply_ressources1(g, gmap->map[y][x], y, x);
			else
				apply_ressources2(g, gmap->map[y][x], y, x);
		}
	}
}

void	print_map_graph(graph_t *g, gmap_t *gmap, client_t *client)
{
	const int tmpx = START_BOX(gmap->width, 0);

	apply_surface(tmpx, 0, g->mainbox, g->screen);
	draw_map_grass(gmap, g->screen, g->smap);
	draw_map_cliff(gmap, g->screen, g->smap);
	print_case(g, gmap);
	print_ressources(g, gmap, 0);
	print_trainers(g, client);
	print_ressources(g, gmap, 1);
	print_mainbox(g, client, gmap->width);
	SDL_Flip(g->screen);
	(void)gmap;
}
