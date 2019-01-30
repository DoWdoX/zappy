/*
** EPITECH PROJECT, 2018
** take_food
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

int set_food(int fd, client_t *client, map_t *ch)
{
	(void)(fd);
	(void)(client);
	(void)(ch);
	if (client->players->food >= 1) {
		client->players->food -= 1;
		(*ch).food += 1;
		write(fd, "ok\n", 3);
	}
	else
		write(fd, "ko\n", 3);
	return (0);
}
