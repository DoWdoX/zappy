/*
** EPITECH PROJECT, 2018
** level5.c
** File description:
** level5
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

incantation_t	*level5(void)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	requirement->players = 4;
	requirement->stones.linemate = 1;
	requirement->stones.deraumere = 2;
	requirement->stones.sibur = 1;
	requirement->stones.mendiane = 3;
	requirement->stones.phiras = 0;
	requirement->stones.thystam = 0;
	return (requirement);
}
