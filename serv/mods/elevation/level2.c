/*
** EPITECH PROJECT, 2018
** level2.c
** File description:
** level2
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

incantation_t	*level2(void)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	requirement->players = 2;
	requirement->stones.linemate = 1;
	requirement->stones.deraumere = 1;
	requirement->stones.sibur = 1;
	requirement->stones.mendiane = 0;
	requirement->stones.phiras = 0;
	requirement->stones.thystam = 0;
	return (requirement);
}
