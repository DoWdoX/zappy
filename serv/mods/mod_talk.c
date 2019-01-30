/*
** EPITECH PROJECT, 2018
** mod_talk.c
** File description:
** 
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

static char *get_text(char *buf)
{
	char *object = malloc(sizeof(char) * 32000);
	int i = 0;
	int j = 0;

	while (buf[i] != ' ')
		i++;
	while (buf[i] == ' ')
		i++;
	while (buf[i]) {
		object[j] = buf[i];
		i++;
		j++;
	}
	object[j] = '\0';
	return (object);
}

int	mod_talk(int fd, char *buf, client_t *client, gmap_t *map)
{
	client_t *tmp = client;
	char *text = malloc(sizeof(char) * 32000);

	text = get_text(buf);
	while (tmp) {
		write(tmp->client_fd, text, strlen(text) + 1);
		tmp = tmp->next;
	}
	tmp = client->prev;
	while (tmp) {
		if (tmp->client_fd != fd)
			write(tmp->client_fd, text, strlen(text) + 1);
		tmp = tmp->prev;
	}
	(void)(map);
	return (0);
}
