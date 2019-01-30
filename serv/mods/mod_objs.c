/*
** EPITECH PROJECT, 2018
** mod_objs.c
** File description:
** 
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

extern t_funcptr_take g_ta[];
extern t_funcptr_take g_set[];

int mod_inventory(int fd, char *buf, client_t *client, gmap_t *gmap)
{
	char *res = malloc(sizeof(char) * 32000);
	char *tmp = malloc(sizeof(char) * 32000);
	stones_t b = client->players->stones;

	bzero(res, 32000);
	sprintf(tmp, "[food %d, ", client->players->food);
	res = strcat(res, tmp);
	sprintf(tmp, "linemate %d, deraumere %d, ", b.linemate, b.deraumere);
	res = strcat(res, tmp);
	sprintf(tmp, "sibur %d, mendiane %d, ", b.sibur, b.mendiane);
	res = strcat(res, tmp);
	sprintf(tmp, "phiras %d, thystam %d]\n", b.phiras, b.thystam);
	res = strcat(res, tmp);
	write(fd, res, strlen(res));
	(void)(gmap);
	(void)(buf);
	return (0);
}

static char *get_object(char *buf)
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

int mod_take(int fd, char *buf, client_t *client, gmap_t *gmap)
{
	map_t *ch = &(gmap->map[client->players->y][client->players->x]);
	char *object = malloc(sizeof(char) * 32000);
	int i = 0;

	object = get_object(buf);
	while (i < 7) {
		if (strncmp(object, g_ta[i].buf, strlen(g_ta[i].buf)) == 0) {
			g_ta[i].funcptr(fd, client, ch);
			return (0);
		}
		i += 1;
	}
	if (i == 7)
		write(fd, "ko\n", 3);
	return (0);
}

int mod_set(int fd, char *buf, client_t *client, gmap_t *gmap)
{
	map_t *ch = &(gmap->map[client->players->y][client->players->x]);
	char *object = malloc(sizeof(char) * 32000);
	int i = 0;

	object = get_object(buf);
	while (i < 7) {
		if (strncmp(object, g_set[i].buf, strlen(g_set[i].buf)) == 0) {
			g_set[i].funcptr(fd, client, ch);
			return (0);
		}
		i += 1;
	}
	if (i == 7)
		write(fd, "ko\n", 3);
	return (0);
}
