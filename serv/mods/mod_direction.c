/*
** EPITECH PROJECT, 2018
** direction
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

int mod_right(int fd, char *buf, client_t *client, gmap_t *map)
{

	(void)buf;
	(void)map;
	client->players->direction += 1;
	if (client->players->direction == 4)
		client->players->direction = 0;
	write(fd, "ok\n", 3);
	return (0);
}

int mod_left(int fd, char *buf, client_t *client, gmap_t *map)
{
	(void)buf;
	(void)map;
	if (client->players->direction == 0)
		client->players->direction = 3;
	else
		client->players->direction -= 1;
	write(fd, "ok\n", 3);
	return (0);
}
