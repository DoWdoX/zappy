/*
** EPITECH PROJECT, 2018
** lookPhiras.c
** File description:
** lookPhiras
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*phiras(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.stones.phiras != 0) {
		i = cha.stones.phiras;
		while (i > 0) {
			strcat(res1, "phiras ");
			i--;
		}
	}
	return (res1);
}
