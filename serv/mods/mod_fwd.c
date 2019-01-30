/*
** EPITECH PROJECT, 2018
** mod
** File description:
** zappy
*/

#include <unistd.h>
#include <stdio.h>
#include "serv.h"
#include "funcptr.h"

extern t_dirptr g_dir[];

void move_up(client_t *client, gmap_t *map)
{
	if (client->players->y == 0)
		client->players->y = map->height - 1;
	else
		client->players->y -= 1;
}

void move_down(client_t *client, gmap_t *map)
{
	if (client->players->y == map->height - 1)
		client->players->y = 0;
	else
		client->players->y += 1;
}

void move_right(client_t *client, gmap_t *map)
{
	if (client->players->x == map->width - 1)
		client->players->x = 0;
	else
		client->players->x += 1;
}

void move_left(client_t *client, gmap_t *map)
{
	if (client->players->x == 0)
		client->players->x = map->width - 1;
	else
		client->players->x -= 1;
}

int mod_fwd(int fd, char *buf, client_t *client, gmap_t *map)
{
	int i = 0;

	sub_player_on_map(map, client->players);
	while (i < 4) {
		if ((unsigned int)client->players->direction == g_dir[i].dir) {
			g_dir[i].fptr(client, map);
			break;
		}
		i += 1;
	}
	printf("Y = %d; X = %d\n", client->players->y, client->players->x);
	add_player_on_map(map, client->players);
	write(fd, "ok\n", 3);
	(void)buf;
	return (0);
}
