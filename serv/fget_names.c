/*
** EPITECH PROJECT, 2018
** fget_names.c
** File description:
** 
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "serv.h"

static char	**init_cmp(void)
{
	char **r = malloc(sizeof(char *) * 6);

	r[0] = "-p";
	r[1] = "-x";
	r[2] = "-y";
	r[3] = "-n";
	r[4] = "-c";
	r[5] = "-f";
	return (r);
}

static int	search_flag(char *s, char **tab)
{
	for (int i = 0; i < 6; ++i)
		if (!strcmp(s, tab[i]))
			return (1);
	return (0);
}

int	fget_names(int ac, char **av, int *i, params_t *p)
{
	char **cmp = init_cmp();
	int n = 1;

	*i += 1;
	for (int t = *i; t < ac && !search_flag(av[t], cmp); ++t)
		++n;
	if (*i >= ac || n == 1)
		return (-1);
	p->nb_teams = n - 1;
	p->tnames = malloc(sizeof(char *) * n);
	if (!cmp || !p->tnames)
		return (-1);
	for (n = 0; *i + 1 < ac && !search_flag(av[*i + 1], cmp); ++n)
		p->tnames[n] = strdup(av[(*i)++]);
	if (*i < ac && !search_flag(av[*i], cmp))
		p->tnames[n] = strdup(av[*i]);
	return (0);
}
