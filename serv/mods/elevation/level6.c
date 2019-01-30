/*
** EPITECH PROJECT, 2018
** level6.c
** File description:
** level6
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

incantation_t	*level6(void)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	requirement->players = 6;
	requirement->stones.linemate = 1;
	requirement->stones.deraumere = 2;
	requirement->stones.sibur = 3;
	requirement->stones.mendiane = 0;
	requirement->stones.phiras = 1;
	requirement->stones.thystam = 0;
	return (requirement);
}
