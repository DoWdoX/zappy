/*
** EPITECH PROJECT, 2018
** lookDeraumere.c
** File description:
** lookDeraumere
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

char	*deraumere(map_t cha, char *res)
{
	int i = 0;
	char *res1 = malloc(sizeof(char) * 32000);

	(void)(res);
	bzero(res1, 32000);
	if (cha.stones.deraumere != 0) {
		i = cha.stones.deraumere;
		while (i > 0) {
			strcat(res1, "deraumere ");
			i--;
		}
	}
	return (res1);
}
