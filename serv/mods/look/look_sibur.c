/*
** EPITECH PROJECT, 2018
** lookSibur.c
** File description:
** lookSibur
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*sibur(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.stones.sibur != 0) {
		i = cha.stones.sibur;
		while (i > 0) {
			strcat(res1, "sibur ");
			i--;
		}
	}
	return (res1);
}
