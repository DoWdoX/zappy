/*
** EPITECH PROJECT, 2018
** fget_params
** File description:
** 
*/

#include <stdlib.h>
#include "serv.h"

int	fget_port(int ac, char **av, int *i, params_t *p)
{
	*i += 1;
	if (*i >= ac)
		return (-1);
	p->port = atoi(av[*i]);
	if (p->port <= 0)
		return (-1);
	return (0);
}

int	fget_width(int ac, char **av, int *i, params_t *p)
{
	*i += 1;
	if (*i >= ac)
		return (-1);
	p->width = atoi(av[*i]);
	if (p->width <= 0)
		return (-1);
	return (0);
}

int	fget_height(int ac, char **av, int *i, params_t *p)
{
	*i += 1;
	if (*i >= ac)
		return (-1);
	p->height = atoi(av[*i]);
	if (p->height <= 0)
		return (-1);
	return (0);
}

int	fget_cli_nb(int ac, char **av, int *i, params_t *p)
{
	*i += 1;
	if (*i >= ac)
		return (-1);
	p->client_nb = atoi(av[*i]);
	if (p->client_nb <= 0)
		return (-1);
	return (0);
}

int	fget_freq(int ac, char **av, int *i, params_t *p)
{
	*i += 1;
	if (*i >= ac)
		return (-1);
	p->freq = atoi(av[*i]);
	if (p->freq <= 0)
		return (-1);
	return (0);
}
