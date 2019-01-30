/*
** EPITECH PROJECT, 2018
** take_phiras
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

int set_phiras(int fd, client_t *client, map_t *ch)
{
	if (client->players->stones.phiras >= 1) {
		client->players->stones.phiras -= 1;
		(*ch).stones.phiras += 1;
		write(fd, "ok\n", 3);
	}
	else
		write(fd, "ko\n", 3);
	return (0);
}
