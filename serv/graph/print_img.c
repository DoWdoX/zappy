/*
** EPITECH PROJECT, 2018
** print_im
** File description:
** 
*/

#include "graphical.h"
#include "serv.h"

static int	*init_badges_posx(const int width)
{
	int *ret = malloc(sizeof(int) * 9);
	int tmpx = START_BOX(width, 0);

	ret[0] = 0;
	ret[1] = tmpx + 43;
	ret[2] = tmpx + 111;
	ret[3] = tmpx + 175;
	ret[4] = tmpx + 245;
	ret[5] = tmpx + 46;
	ret[6] = tmpx + 109;
	ret[7] = tmpx + 173;
	ret[8] = tmpx + 243;
	return (ret);
}

static int	*init_badges_posy(void)
{
	int *ret = malloc(sizeof(int) * 9);

	ret[0] = 0;
	ret[1] = 423;
	ret[2] = 424;
	ret[3] = 424;
	ret[4] = 423;
	ret[5] = 491;
	ret[6] = 491;
	ret[7] = 492;
	ret[8] = 491;
	return (ret);
}

void	print_badges(graph_t *g, const client_t *active, const int width)
{
	int *posx = init_badges_posx(width);
	int *posy = init_badges_posy();

	for (int i = 1; i <= active->players->elevation; ++i)
		apply_surface(posx[i], posy[i], g->badges[i], g->screen);
	free(posx);
	free(posy);
}

void	print_img_items(graph_t *g, const int width)
{
	int tmpx = START_BOX(width, 65);

	apply_surface(tmpx, 297, g->food, g->screen);
	apply_surface(tmpx, 339, g->balls[0], g->screen);
	apply_surface(tmpx + 90, 339, g->balls[1], g->screen);
	apply_surface(tmpx + 180, 339, g->balls[2], g->screen);
	apply_surface(tmpx, 379, g->balls[3], g->screen);
	apply_surface(tmpx + 90, 379, g->balls[4], g->screen);
	apply_surface(tmpx + 180, 379, g->balls[5], g->screen);
}
