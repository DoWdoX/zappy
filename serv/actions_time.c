/*
** EPITECH PROJECT, 2018
** actions_time.c
** File description:
** 
*/

#include <string.h>
#include <stdlib.h>
#include "serv.h"

static char	**init_action_tab(void)
{
	char **ret = malloc(sizeof(char *) * 10);

	if (!ret)
		return (NULL);
	ret[0] = "Forward";
	ret[1] = "Right";
	ret[2] = "Left";
	ret[3] = "Look";
	ret[4] = "Broadcast ";
	ret[5] = "Fork";
	ret[6] = "Eject";
	ret[7] = "Take ";
	ret[8] = "Set ";
	ret[9] = "Incantation";
	return (ret);
}

static int	*init_times_tab(void)
{
	int *ret = malloc(sizeof(int) * 10);

	if (!ret)
		return (NULL);
	ret[0] = 7;
	ret[1] = 7;
	ret[2] = 7;
	ret[3] = 7;
	ret[4] = 1;
	ret[5] = 7;
	ret[6] = 42;
	ret[7] = 7;
	ret[8] = 7;
	ret[9] = 300;
	return (ret);
}

int	get_action_time(const char *action)
{
	char **action_tab = init_action_tab();
	const int *timestab = init_times_tab();

	if (!action || !timestab || !action_tab)
		return (0);
	for (unsigned int i = 0; i < 10; ++i)
		if (!strncmp(action, action_tab[i], strlen(action_tab[i])))
			return (timestab[i]);
	return (0);
}
