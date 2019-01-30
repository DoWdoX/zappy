/*
** EPITECH PROJECT, 2018
** params.c
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "serv.h"
#include "fptrtab.h"

static int	*init_values_set(void)
{
	int *v = malloc(sizeof(int) * 6);

	if (v) {
		v[0] = 0;
		v[1] = 0;
		v[2] = 0;
		v[3] = 0;
		v[4] = 0;
		v[5] = 1;
	}
	return (v);
}

static fptrtab_t	*init_ftab(void)
{
	fptrtab_t *r = malloc(sizeof(fptrtab_t) * 6);

	if (!r)
		return (NULL);
	r[0].cmp = "-p";
	r[1].cmp = "-x";
	r[2].cmp = "-y";
	r[3].cmp = "-n";
	r[4].cmp = "-c";
	r[5].cmp = "-f";
	r[0].f = fget_port;
	r[1].f = fget_width;
	r[2].f = fget_height;
	r[3].f = fget_names;
	r[4].f = fget_cli_nb;
	r[5].f = fget_freq;
	return (r);
}

static int	error_unset(int err)
{
	switch (err) {
	case 0:
		printf("Port not specified\n");
		break;
	case 1:
		printf("Map width not specified\n");
		break;
	case 2:
		printf("Map height not specified\n");
		break;
	case 3:
		printf("No team name specified\n");
		break;
	case 4:
		printf("Number of client per team not specified\n");
		break;
	}
	return (-1);
}

int	get_params_loop(int ac, char **av, int *i, params_t *p)
{
	const fptrtab_t *ftab = init_ftab();
	int rescmp;

	if (!ftab)
		return (-1);
	for (int j = 0; *i < ac && j < 6; ++j) {
		rescmp = strcmp(ftab[j].cmp, av[*i]);
		if (!rescmp && ftab[j].f(ac, av, i, p) != 0)
			return (-1);
		else if (!rescmp)
			return (j);
	}
	printf("Flag \"%s\" not found\n", av[*i]);
	return (-1);
}

int	get_params(int ac, char **av, params_t *p)
{
	int *values_set = init_values_set();
	int ret;

	if (!values_set)
		return (-1);
	for (int p = 1; p < ac; ++p)
		if (!strcmp(av[p], "-help"))
			return (usage(av[0]));
	for (int i = 1; i < ac; ++i) {
		ret = get_params_loop(ac, av, &i, p);
		if (ret == -1)
			return (-1);
		values_set[ret] = 1;
	}
	for (int p = 0; p < 6; ++p)
		if (values_set[p] == 0)
			return (error_unset(p));
	return (0);
}
