/*
** EPITECH PROJECT, 2018
** lookDirection.c
** File description:
** lookDirection
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

void	look_up(int elevation, gmap_t *gmap, client_t *client, map_t **cha)
{
	int x = client->players->x - elevation + 1;
	int y = client->players->y - elevation + 1;
	int counter;

	for (counter = 1; counter <= (elevation * 2 - 1); counter += 1) {
		int tmp_x = x;
		if (x < 0)
			tmp_x = gmap->width + x;
		else if (x > gmap->width - 1)
			tmp_x = x - gmap->width;
		int tmp_y = y;
		if (y < 0)
			tmp_y = gmap->height + y;
		(*cha)[counter - 1] = gmap->map[tmp_y][tmp_x];
		x += 1;
	}
}

void	look_down(int elevation, gmap_t *gmap, client_t *client, map_t **cha)
{
	int x = client->players->x + elevation - 1;
	int y = client->players->y + elevation - 1;
	int counter;

	for (counter = 1; counter <= (elevation * 2 - 1); counter += 1) {
		int tmp_x = x;
		if (x < 0)
			tmp_x = gmap->width + x;
		else if (x > gmap->width - 1)
			tmp_x = x - gmap->width;
		int tmp_y = y;
		if (y > gmap->height - 1)
			tmp_y = y - gmap->height;
		(*cha)[counter - 1] = gmap->map[tmp_y][tmp_x];
		x -= 1;
	}
}

void	look_left(int elevation, gmap_t *gmap, client_t *client, map_t **cha)
{
	int x = client->players->x - elevation + 1;
	int y = client->players->y + elevation - 1;
	int counter;

	for (counter = 1; counter <= (elevation * 2 - 1); counter += 1) {
		int tmp_x = x;
		if (x < 0)
			tmp_x = gmap->width + x;
		int tmp_y = y;
		if (y < 0)
			tmp_y = gmap->height + y;
		else if (y > gmap->height - 1)
			tmp_y = y - gmap->height;
		(*cha)[counter - 1] = gmap->map[tmp_y][tmp_x];
		y -= 1;
	}
}

void	look_right(int elevation, gmap_t *gmap, client_t *client, map_t **cha)
{
	int x = client->players->x + elevation - 1;
	int y = client->players->y - elevation + 1;
	int counter;

	for (counter = 1; counter <= (elevation * 2 - 1); counter += 1) {
		int tmp_x = x;
		if (x > gmap->width - 1)
			tmp_x = x - gmap->width;
		int tmp_y = y;
		if (y < 0)
			tmp_y = gmap->height + y;
		else if (y > gmap->height - 1)
			tmp_y = y - 21;
		(*cha)[counter - 1] = gmap->map[tmp_y][tmp_x];
		y += 1;
	}
}
