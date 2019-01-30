/*
** EPITECH PROJECT, 2018
** print_text.c
** File description:
** 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "serv.h"
#include "graphical.h"

void	text_printer(graph_t *g, char *mess, int x, int y)
{
	SDL_Surface *srf;

	srf = TTF_RenderText_Solid(g->basefont, mess, g->color);
	apply_surface(x, y, srf, g->screen);
}

char	**init_tmp_stones(stones_t *stones)
{
	char **tmp = malloc(sizeof(char *) * 6);
	int p = 0;

	for (int i = 0; i < 6; ++i)
		tmp[i] = malloc(sizeof(char) * 10);
	sprintf(tmp[p++], "x%d", stones->linemate);
	sprintf(tmp[p++], "x%d", stones->deraumere);
	sprintf(tmp[p++], "x%d", stones->sibur);
	sprintf(tmp[p++], "x%d", stones->mendiane);
	sprintf(tmp[p++], "x%d", stones->phiras);
	sprintf(tmp[p++], "x%d", stones->thystam);
	return (tmp);
}

void	print_text_stones(graph_t *g, stones_t stones, const int width)
{
	char **tmp = init_tmp_stones(&stones);
	int tmpx = START_BOX(width, 80);
	int p = 0;

	text_printer(g, tmp[p++], tmpx, 330);
	text_printer(g, tmp[p++], tmpx + 90, 330);
	text_printer(g, tmp[p++], tmpx + 180, 330);
	text_printer(g, tmp[p++], tmpx, 370);
	text_printer(g, tmp[p++], tmpx + 90, 370);
	text_printer(g, tmp[p++], tmpx + 180, 370);
}

void	print_text_head(graph_t *g, client_t *active, const int width)
{
	SDL_Surface *mess;
	int tmpx = START_BOX(width, 120);
	char *tmp = malloc(500);

	mess = TTF_RenderText_Solid(g->ttlfont, active->team, g->color);
	apply_surface(tmpx, 20, mess, g->screen);
	sprintf(tmp, "X [%d]     Y[%d]", active->players->x, active->players->y);
	mess = TTF_RenderText_Solid(g->coordfont, tmp, g->color);
	apply_surface(tmpx, 50, mess, g->screen);
}

void	print_text_stats(graph_t *g, client_t *active, const int width)
{
	int tmpx = START_BOX(width, 40);
	char *tmp = malloc(500);

	if (active->action)
		sprintf(tmp, "Curr.  action:  %s", active->action);
	else
		sprintf(tmp, "Just chilling");
	text_printer(g, tmp, tmpx, 130);
	bzero(tmp, 500);
	sprintf(tmp, "Hungryness   [%d/126]", active->players->hungryness);
	text_printer(g, tmp, tmpx, 160);
	bzero(tmp, 500);
	sprintf(tmp, "x%d", active->players->food);
	text_printer(g, tmp, tmpx + 40, 290);
}
