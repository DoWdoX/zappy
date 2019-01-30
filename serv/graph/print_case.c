/*
** EPITECH PROJECT, 2018
** print_case.c
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include "graphical.h"
#include "serv.h"

static void	print_imgs_case(graph_t *g, int width)
{
	const int tmpx = START_BOX(width, 65);
	const int base = 368;

	apply_surface(tmpx + 180, base + 298, g->food, g->screen);
	apply_surface(tmpx, base + 333, g->balls[0], g->screen);
	apply_surface(tmpx + 90, base + 333, g->balls[1], g->screen);
	apply_surface(tmpx + 180, base + 333, g->balls[2], g->screen);
	apply_surface(tmpx, base + 368, g->balls[3], g->screen);
	apply_surface(tmpx + 90, base + 366, g->balls[4], g->screen);
	apply_surface(tmpx + 180, base + 366, g->balls[5], g->screen);
}

void	print_text_case(graph_t *g, map_t tile, int width)
{
	char **tmp = init_tmp_stones(&tile.stones);
	char *tmpfood = malloc(sizeof(char) * 10);
	const int tmpx = START_BOX(width, 83);
	const int base = 359;
	int p = 0;

	sprintf(tmpfood, "x%d", tile.food);
	text_printer(g, tmpfood, tmpx + 180, base + 300);
	text_printer(g, tmp[p++], tmpx, base + 333);
	text_printer(g, tmp[p++], tmpx + 90, base + 333);
	text_printer(g, tmp[p++], tmpx + 180, base + 333);
	text_printer(g, tmp[p++], tmpx, base + 366);
	text_printer(g, tmp[p++], tmpx + 90, base + 366);
	text_printer(g, tmp[p++], tmpx + 180, base + 366);
}

void	print_case(graph_t *g, gmap_t *gmap)
{
	const int tmpx = START + TILE_SIZE * g->x_detail;
	const int tmpy = START + TILE_SIZE * g->y_detail;
	char *tmpcase = malloc(sizeof(char) * 30);

	if (g->x_detail == -1 || g->y_detail == -1)
		return;
	apply_surface(tmpx, tmpy, g->mark, g->screen);
	print_imgs_case(g, gmap->width);
	print_text_case(g, gmap->map[g->y_detail][g->x_detail], gmap->width);
	sprintf(tmpcase, "X [%d]  /  Y [%d]", g->y_detail, g->x_detail);
	text_printer(g, tmpcase, START_BOX(gmap->width, 40), 660);
	free(tmpcase);
}
