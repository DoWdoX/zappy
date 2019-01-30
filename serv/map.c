/*
** EPITECH PROJECT, 2018
** init_map.c
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "serv.h"

# define H gmap->height
# define W gmap->width

void print_map(client_t *client, gmap_t *gmap)
{
	int i = 0;
	int j = 0;
	char *send = malloc(sizeof(char) * (H * W + H + 1));
	char *buf = malloc(sizeof(char) * 2);

	buf[1] = '\0';
	while (j < gmap->height) {
		i = 0;
		while (i < gmap->width) {
			buf[0] = print_player(gmap->map[j][i].ch);
			send = strcat(send, buf);
			++i;
		}
		send = strcat(send, "\n");
		++j;
	}
	dprintf(client->client_fd, "%s", send);
}

void sub_player_on_map(gmap_t *gmap, characters_t *player)
{
	characters_t *tmp = gmap->map[player->y][player->x].ch;

	if (tmp && !tmp->map_next)
		gmap->map[player->y][player->x].ch = NULL;
	if (tmp && tmp->map_next && tmp == player) {
		gmap->map[player->y][player->x].ch = tmp->map_next;
		return;
	}
	while (tmp && tmp->map_next) {
		if (tmp->map_next == player) {
			tmp->map_next = tmp->map_next->map_next;
			break;
		}
		tmp = tmp->map_next;
	}
}

void add_player_on_map(gmap_t *gmap, characters_t *player)
{
	characters_t *tmp = gmap->map[player->y][player->x].ch;

	player->map_next = NULL;
	if (!tmp)
		gmap->map[player->y][player->x].ch = player;
	else {
		while (tmp && tmp->map_next) {
			tmp = tmp->map_next;
		}
		tmp->map_next = player;
	}
}

static map_t init_map_content(void)
{
	map_t map;

	map.ch = NULL;
	map.food = my_rand_stones(2);
	map.stones = init_rand_stones();
	return (map);
}

gmap_t init_map(int height, int width)
{
	map_t **map = malloc(sizeof(map_t*) * (height + 1));
	gmap_t gmap;
	time_t t;

	srand((unsigned)time(&t));
	for (int j = 0; map && j < height; ++j) {
		map[j] = malloc(sizeof(map_t) * (width + 1));
		for (int i = 0; map[j] && i < width; ++i)
			map[j][i] = init_map_content();
	}
	gmap.map = map;
	gmap.height = height;
	gmap.width = width;
	return (gmap);
}
