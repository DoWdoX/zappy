/*
** EPITECH PROJECT, 2018
** mod_elevate.c
** File description:
** 
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"
#include "funcptr.h"

bool check_requirement(client_t *client, gmap_t *map, incantation_t *r)
{
	int y = client->players->y;
	int x = client->players->x;
	stones_t stones = map->map[y][x].stones;
	characters_t *cha = map->map[y][x].ch;
	int counter = 0;

	while (cha) {
		if (client && cha->elevation == client->players->elevation)
			counter += 1;
		cha = cha->map_next;
	}
	if (r->stones.linemate >= stones.linemate &&
		r->stones.deraumere >= stones.deraumere &&
		r->stones.sibur >= stones.sibur &&
		r->stones.mendiane >= stones.mendiane &&
		r->stones.phiras >= stones.phiras &&
		r->stones.thystam >= stones.thystam &&
		r->players >= counter)
		return (true);
	return (false);
}

void my_incantation(client_t *client, gmap_t *map, incantation_t *r, int fd)
{
	if (check_requirement(client, map, r) == true) {
		int x = client->players->x;
		int y = client->players->y;
		map->map[y][x].stones.linemate -= r->stones.linemate;
		map->map[y][x].stones.deraumere -= r->stones.deraumere;
		map->map[y][x].stones.sibur -= r->stones.sibur;
		map->map[y][x].stones.mendiane -= r->stones.mendiane;
		map->map[y][x].stones.phiras -= r->stones.phiras;
		map->map[y][x].stones.thystam -= r->stones.thystam;
		client->players->elevation += 1;
		char *str = malloc(sizeof(char) * 20);
		sprintf(str, "Current level: %d\n", client->players->elevation);
		write(fd, str, strlen(str));
	}
	else {
		char *str = malloc(sizeof(char) * 20);
		sprintf(str, "Current level: %d\n", client->players->elevation);
		write(fd, str, strlen(str));
	}
}

incantation_t *other_levels(int elevation)
{
	incantation_t *requirement;

	switch (elevation) {
	case 5:
		requirement = level5();
		break;
	case 6:
		requirement = level6();
		break;
	case 7:
		requirement = level7();
		break;
	};
	return (requirement);
}

int mod_elevate(int fd, char *buf, client_t *client, gmap_t *map)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	(void) buf;
	switch (client->players->elevation) {
	case 1:
		requirement = level1();
		break;
	case 2:
		requirement = level2();
		break;
	case 3:
		requirement = level3();
		break;
	case 4:
		requirement = level4();
		break;
	default:
		requirement = other_levels(client->players->elevation);
	};
	my_incantation(client, map, requirement, fd);
	return (0);
}
