/*
** EPITECH PROJECT, 2018
** level1.c
** File description:
** level1
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

incantation_t	*level1(void)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	requirement->players = 1;
	requirement->stones.linemate = 1;
	requirement->stones.deraumere = 0;
	requirement->stones.sibur = 0;
	requirement->stones.mendiane = 0;
	requirement->stones.phiras = 0;
	requirement->stones.thystam = 0;
	return (requirement);
}
