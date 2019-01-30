/*
** EPITECH PROJECT, 2018
** init_back.c
** File description:
** 
*/

#include <stdlib.h>
#include "serv.h"
#include "graphical.h"

/* static SDL_Surface	*rand_grass(SDL_Surface **grass) */
/* { */
/* 	int res; */
	
/* 	res = rand() % 20; */
/* 	if (res > 5) */
/* 		res = 0; */
/* 	return (grass[res]); */
/* } */

smap_t	*load_map_ressources(void)
{
	smap_t *sprites_map = malloc(sizeof(smap_t));

	sprites_map->grass = malloc(sizeof(SDL_Surface *) * 6);
	sprites_map->grass[0] = load_image(PATH_GRASS_0);
	sprites_map->grass[1] = load_image(PATH_GRASS_1);
	sprites_map->grass[2] = load_image(PATH_GRASS_2);
	sprites_map->grass[3] = load_image(PATH_GRASS_3);
	sprites_map->grass[4] = load_image(PATH_GRASS_4);
	sprites_map->grass[5] = load_image(PATH_GRASS_5);
	sprites_map->left = load_image(PATH_LEFT);
	sprites_map->right = load_image(PATH_RIGHT);
	sprites_map->up = load_image(PATH_UP);
	sprites_map->down = load_image(PATH_DOWN);
	sprites_map->up_left = load_image(PATH_UP_LEFT);
	sprites_map->up_right = load_image(PATH_UP_RIGHT);
	sprites_map->down_left = load_image(PATH_DOWN_LEFT);
	sprites_map->down_right = load_image(PATH_DOWN_RIGHT);
	return (sprites_map);
}

void	draw_map_grass(const gmap_t *map, SDL_Surface *back, const smap_t *s)
{
	int tmpx;
	int tmpy;

	for (int y = 0; y < map->height; ++y) {
		tmpx = START - TILE_SIZE * 2;
		tmpy = START + TILE_SIZE * y;
		apply_surface(tmpx, tmpy, s->left, back);
		for (int x = 0; x < map->width; ++x) {
			tmpx = START + TILE_SIZE * x;
			tmpy = START + TILE_SIZE * y;
			apply_surface(tmpx, tmpy, s->grass[0], back);
		}
		tmpx = START + TILE_SIZE * map->width;
		tmpy = START + TILE_SIZE * y;
		apply_surface(tmpx, tmpy, s->right, back);
	}
}

void	draw_map_cliff(const gmap_t *map, SDL_Surface *back, const smap_t *s)
{
	const int tmpy = START + map->height * TILE_SIZE;
	int tmpx;

	apply_surface(0, 0, s->up_left, back);
	for (int i = 0; i < map->width; ++i)
		apply_surface(START + TILE_SIZE * i, 0, s->up, back);
	apply_surface(START + map->width * TILE_SIZE, 0, s->up_right, back);
	apply_surface(0, START + TILE_SIZE * map->height, s->down_left, back);
	for (int i = 0; i < map->width; ++i) {
		tmpx = START + TILE_SIZE * i;
		apply_surface(tmpx, tmpy, s->down, back);
	}
	tmpx = START + map->width * TILE_SIZE;
	apply_surface(tmpx, tmpy, s->down_right, back);
}
