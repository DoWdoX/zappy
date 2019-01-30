/*
** EPITECH PROJECT, 2018
** stones.c
** File description:
** 
*/

#include <time.h>
#include <stdlib.h>
#include "serv.h"

int	my_rand_stones(int base)
{
	int nb = 0;
	int res = 0;

	while (res == 0) {
		res = rand() % base;
		if (res == 0)
			++nb;
		++base;
	}
	return (nb);
}

stones_t	init_rand_stones(void)
{
	stones_t st;

	st.linemate = my_rand_stones(2);
	st.deraumere = my_rand_stones(2);
	st.sibur = my_rand_stones(2);
	st.mendiane = my_rand_stones(3);
	st.phiras = my_rand_stones(3);
	st.thystam = my_rand_stones(6);
	return (st);
}

stones_t	init_stones(void)
{
	stones_t st;

	st.linemate = 0;
	st.deraumere = 0;
	st.sibur = 0;
	st.mendiane = 0;
	st.phiras = 0;
	st.thystam = 0;
	return (st);
}
