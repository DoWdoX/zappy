/*
** EPITECH PROJECT, 2018
** look_food
** File description:
** zappy
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char *food(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.food != 0) {
		i = cha.food;
		while (i > 0) {
			strcat(res1, "food ");
			i--;
		}
	}
	return (res1);
}
