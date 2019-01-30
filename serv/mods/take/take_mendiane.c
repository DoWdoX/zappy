/*
** EPITECH PROJECT, 2018
** take_mendiane
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

int take_mendiane(int fd, client_t *client, map_t *ch)
{
	if (ch->stones.mendiane >= 1) {
		client->players->stones.mendiane += 1;
		(*ch).stones.mendiane -= 1;
		write(fd, "ok\n", 3);
	}
	else
		write(fd, "ko\n", 3);
	return (0);
}
