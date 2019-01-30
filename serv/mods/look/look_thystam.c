/*
** EPITECH PROJECT, 2018
** lookThystam.c
** File description:
** lookThystam
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*thystam(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.stones.thystam != 0) {
		i = cha.stones.linemate;
		while (i > 0) {
			strcat(res1, "thystam ");
			i--;
		}
	}
	return (res1);
}
