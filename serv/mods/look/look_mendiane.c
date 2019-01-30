/*
** EPITECH PROJECT, 2018
** lookMendiane.c
** File description:
** lookMendiane
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*mendiane(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.stones.mendiane != 0) {
		i = cha.stones.mendiane;
		while (i > 0) {
			strcat(res1, "mendiane ");
			i--;
		}
	}
	return (res1);
}
