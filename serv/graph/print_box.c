/*
** EPITECH PROJECT, 2018
** print_mainbox.c
** File description:
** 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serv.h"
#include "graphical.h"

static void	print_icon(graph_t *g, client_t *active, int width)
{
	int tmpx = START_BOX(width, 16);
	int len = strlen(PATH_TRAINER) + strlen(active->team) + 10;
	char *path = malloc(sizeof(char) * len);
	SDL_Surface *icon;

	path = strcpy(path, PATH_TRAINER);
	path = strcat(path, active->team);
	path = strcat(path, "_icone.png");
	icon = load_image_png(path);
	apply_surface(tmpx, 16, icon, g->screen);
}

static void	print_infos(graph_t *g, client_t *active, int width)
{
	print_icon(g, active, width);
	print_text_head(g, active, width);
	print_text_stats(g, active, width);
	print_text_stones(g, active->players->stones, width);
	print_img_items(g, width);
	print_badges(g, active, width);
}

void	print_mainbox(graph_t *g, client_t *client, int width)
{
	client_t *tmp = client;

	if (g->selected == -1) {
		if (client)
			g->selected = 1;
		else
			return;
	}
	for (int i = 1; tmp && i < g->selected; ++i)
		tmp = tmp->next;
	print_infos(g, tmp, width);
}
