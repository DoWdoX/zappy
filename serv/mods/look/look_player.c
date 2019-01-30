/*
** EPITECH PROJECT, 2018
** look_player
** File description:
** zappy
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char *player(map_t cha, char *res)
{
	characters_t *tmp = cha.ch;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	while (tmp) {
		strcat(res1, "player ");
		tmp = tmp->map_next;
	}
	return (res1);
}

