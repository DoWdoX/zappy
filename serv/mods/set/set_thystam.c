/*
** EPITECH PROJECT, 2018
** take_thystam
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

int set_thystam(int fd, client_t *client, map_t *ch)
{
	if (client->players->stones.thystam >= 1) {
		client->players->stones.thystam -= 1;
		(*ch).stones.thystam += 1;
		write(fd, "ok\n", 3);
	}
	else
		write(fd, "ko\n", 3);
	return (0);
}
