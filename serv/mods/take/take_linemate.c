/*
** EPITECH PROJECT, 2018
** take_linemate
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

int take_linemate(int fd, client_t *client, map_t *ch)
{
	if (ch->stones.linemate >= 1) {
		client->players->stones.linemate += 1;
		(*ch).stones.linemate -= 1;
		write(fd, "ok\n", 3);
	}
	else
		write(fd, "ko\n", 3);
	return (0);
}
