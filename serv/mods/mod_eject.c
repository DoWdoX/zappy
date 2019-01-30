/*
** EPITECH PROJECT, 2018
** mod_eject.c
** File description:
** mod_eject
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*coming_eject(int res_x, int res_y)
{
	char *str = malloc(sizeof(char) * 16);

	if (res_x == 0) {
		if (res_y == -1)
			strcpy(str, "eject: TOP\n");
		else if (res_y == 1)
			strcpy(str, "eject: DOWN\n");
	}
	else if (res_y == 0) {
		if (res_x == -1)
			strcpy(str, "eject: LEFT\n");
		else if (res_x == 1)
			strcpy(str, "eject: RIGHT\n");
	}
	return (str);
}

void	check_direction_to_eject(characters_t *tmp, int x, int y)
{
	int res_x = tmp->x - x;
	int res_y = tmp->y - y;
	char *str = strdup(coming_eject(res_x, res_y));
	write(tmp->client_fd, str, strlen(str));
}

void	modif_x_y(int *x, int *y, gmap_t *gmap)
{
	if (*x < 0)
		*x += gmap->width;
	else if (*x > gmap->width - 1)
		*x -= gmap->width;
	if (*y < 0)
		*y += gmap->height;
	else if (*y > gmap->height - 1)
		*y -= gmap->height;
}

void	eject_all(client_t *client, int new_x, int new_y, gmap_t *gmap)
{
	int old_x = client->players->x;
	int old_y = client->players->y;
	characters_t *tmp = gmap->map[old_y][old_x].ch;

	while (tmp) {
		if (tmp->client_fd != client->client_fd) {
			check_direction_to_eject(tmp, new_x, new_y);
			tmp = tmp->map_next;
		}
	}
	client->players->x = old_x;
	client->players->y = old_y;
}

int	mod_eject(int fd, char *buf, client_t *c, gmap_t *gmap)
{
	switch (c->players->direction) {
	case TOP:
		eject_all(c, c->players->x, c->players->y - 1, gmap);
		break;
	case DOWN:
		eject_all(c, c->players->x, c->players->y + 1, gmap);
		break;
	case RIGHT:
		eject_all(c, c->players->x + 1, c->players->y, gmap);
		break;
	case LEFT:
		eject_all(c, c->players->x - 1, c->players->y, gmap);
		break;
	};
	(void) fd;
	(void) buf;
	return (0);
}
