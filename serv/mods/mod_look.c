/*
** EPITECH PROJECT, 2018
** mod_look.c
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

typedef char *(*f)(map_t, char *);
char *linemate(map_t, char *);
char *deraumere(map_t, char *);
char *sibur(map_t, char *);
char *mendiane(map_t, char *);
char *phiras(map_t, char *);
char *thystam(map_t, char *);
char *food(map_t, char *);
char *player(map_t, char *);
f ptrLook[] = { linemate, deraumere, sibur, mendiane, phiras,
	thystam, food, player };

char	*loop_look(map_t cha)
{
	char *res = malloc(sizeof(char) * 32000);
	for (int i = 0; i < 8; i += 1) {
		if (strcmp(res, ptrLook[i](cha, res)) != 0)
			strcat(res, ptrLook[i](cha, res));
	}
	return (res);
}

void	parse_case(int i, map_t *cha, char **res, int counter)
{
	for (int j = 0; j < (i * 2 - 1); j += 1) {
		strcat(*res, loop_look(cha[j]));
		if ((j + 1) < (i * 2 - 1))
			strcat(*res, ", ");
		counter += 1;
		printf("|%d|", counter);
	}
}

char	*vision(gmap_t *gmap, characters_t *cho, client_t *client, int counter)
{
	char *res = malloc(sizeof(char) * 32000);
	for (int i = 1; i <= cho->elevation && i <= 8; i += 1) {
		map_t *cha = malloc(sizeof(map_t) * (i * 2));
		switch (cho->direction) {
		case TOP:
			look_up(i, gmap, client, &cha);
			break;
		case DOWN:
			look_down(i, gmap, client, &cha);
			break;
		case LEFT:
			look_left(i, gmap, client, &cha);
			break;
		case RIGHT:
			look_right(i, gmap, client, &cha);
			break;
		};
		parse_case(i, cha, &res, counter);
	}
	return (res);
}

int	mod_look(int fd, char *buf, client_t *client, gmap_t *gmap)
{
	int x = client->players->x;
	int y = client->players->y;
	characters_t *cho = gmap->map[y][x].ch;
	char *res = malloc(sizeof(char) * 32000);

	bzero(res, 32000);
	res[0] = '[';
	strcat(res, vision(gmap, cho, client, 0));
	res[strlen(res) - 1] = ']';
	write(fd, res, strlen(res) + 1);
	(void)(buf);
	return (0);
}
