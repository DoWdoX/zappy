/*
** EPITECH PROJECT, 2018
** level7.c
** File description:
** level7
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serv.h"
#include "funcptr.h"

incantation_t	*level7(void)
{
	incantation_t *requirement = malloc(sizeof(incantation_t));

	requirement->players = 6;
	requirement->stones.linemate = 2;
	requirement->stones.deraumere = 2;
	requirement->stones.sibur = 2;
	requirement->stones.mendiane = 2;
	requirement->stones.phiras = 2;
	requirement->stones.thystam = 1;
	return (requirement);
}
