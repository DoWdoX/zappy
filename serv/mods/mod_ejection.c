/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** mod_ejection
*/

#include "serv.h"
#include "funcptr.h"

int	mod_ejection(int fd, char *buf, client_t *client, gmap_t *map)
{
	(void)(fd);
	(void)(buf);
	(void)(client);
	(void)(map);
	write(fd, "ok\n", 3);
	return (0);
}
