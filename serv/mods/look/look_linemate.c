/*
** EPITECH PROJECT, 2018
** lookLinemate.c
** File description:
** lookLinemate
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*linemate(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.stones.linemate != 0) {
		i = cha.stones.linemate;
		while (i > 0) {
			strcat(res1, "linemate ");
			i--;
		}
	}
	return (res1);
}
