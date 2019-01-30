/*
** EPITECH PROJECT, 2018
** creation
** File description:
** zappy
*/

#include <unistd.h>
#include "serv.h"

int creation(int cfd, int *nbc, client_t **client, gmap_t *gmap)
{
	write(cfd, "WELCOME\n", 8);
	create(*nbc, client, cfd, gmap);
	++(*nbc);
	return (0);
}
