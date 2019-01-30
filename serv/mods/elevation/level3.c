/*
** EPITECH PROJECT, 2018
** level3.c
** File description:
** level3
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

incantation_t	*level3(void)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	requirement->players = 2;
	requirement->stones.linemate = 2;
	requirement->stones.deraumere = 0;
	requirement->stones.sibur = 1;
	requirement->stones.mendiane = 0;
	requirement->stones.phiras = 2;
	requirement->stones.thystam = 0;
	return (requirement);
}
