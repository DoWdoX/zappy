/*
** EPITECH PROJECT, 2018
** hungry.c
** File description:
** hungry
*/

#include <time.h>
#include "ai.h"

int	check_food(char *buf1, char *nb_food_str)
{
	buf1 += 6;
	int i = 0;
	for (; buf1[i] && buf1[i] != ','; i += 1)
		nb_food_str[i] = buf1[i];
	nb_food_str[i] = '\0';
	int nb_food = atoi(nb_food_str);
	return (nb_food);
}

int	hungry(int act, int fd, fd_set rdfs)
{
	char *buff = malloc(sizeof(char) * 32000);
	char *buf1 = malloc(sizeof(char) * 32000);
	char *nb_food_str = malloc(sizeof(char) * 5);
	int message_send = 0;
	(void)(act);
	buff = strdup("Inventory\n");
	if ((message_send = send(fd, buff, strlen(buff), 0)) == -1)
		return (1);
	if (FD_ISSET(fd, &rdfs)) {
		if ((message_send = recv(fd, buf1, 32000 - 1, 0)) == -1)
			return (1);
		else
			buf1[message_send - 1] = '\0';
	}
	if (check_food(buf1, nb_food_str) <= 3)
		return (1);
	return (0);
}
