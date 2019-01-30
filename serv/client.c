/*
** EPITECH PROJECT, 2018
** client
** File description:
** zappy
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "serv.h"

static client_t	*init_client(int cfd, gmap_t *map, char *buf)
{
	client_t *ret = malloc(sizeof(client_t));

	if (!ret)
		return (NULL);
	ret->client_fd = cfd;
	ret->players = add_player_on_client(ret, map);
	ret->action = NULL;
	ret->time_action = 0;
	ret->actions_queue = NULL;
	ret->alive = 1;
	ret->prev = NULL;
	ret->next = NULL;
	add_player_on_map(map, ret->players);
	dprintf(ret->client_fd, "%d %d\n", ret->players->x, ret->players->y);
	ret->team = strdup(buf);
	printf("buf1 : %s\n", buf);
	return (ret);
}

static int add_client(client_t **client, int cfd, gmap_t *map, char *buf)
{
	client_t *new = init_client(cfd, map, buf);
	client_t *tmp = *client;

	if (!new)
		return (-1);
	if (tmp) {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->prev = tmp;
	return (0);
}

static int connect_to_client(int fd, int nbc, gmap_t *map, char *buf)
{
	int i = 0;

	while (i < map->nb_teams) {
		if (strncmp(buf, map->tnames[i], strlen(buf)) == 0) {
			dprintf(fd, "%d", nbc + 1);
			return (0);
		}
		i++;
	}
	write(fd, "ko\n", 3);
	return (1);
}

int create(int nbc, client_t **client, int cfd, gmap_t *map)
{
	char *buf = malloc(sizeof(char) * 32000);

	bzero(buf, 32000);
	read(cfd, buf, 32000);
	if (nbc == 0) {
		if (connect_to_client(cfd, nbc, map, buf) == 0) {
			*client = init_client(cfd, map, buf);
			printf("first client\n");
		}
	}
	else {
		if (connect_to_client(cfd, nbc, map, buf) == 0) {
			add_client(client, cfd, map, buf);
			printf("new client\n");
		}
	}
	return (0);
}
