/*
** EPITECH PROJECT, 2018
** elevate.c
** File description:
** elevate
*/

#include <time.h>
#include "ai.h"

void	check_elevation(char *buf1, char *nb_food_str, int fd, fd_set rdfs)
{
	buf1 += 6;
	int i = 0;
	for (; buf1[i] && buf1[i] != ','; i += 1)
		nb_food_str[i] = buf1[i];
	nb_food_str[i] = '\0';
	int nb_food = atoi(nb_food_str);
	if (nb_food >= 3) {
		printf("ELEVATIIIIIIIIIIING\n");
		do_command(fd, rdfs, "Incantation\n");
	}
	printf("ELEVATE END\n");
}

int	elevate(int act, int fd, fd_set rdfs)
{
	printf("ELEVATE START\n");
	char *buff = malloc(sizeof(char) * 32000);
	char *buf1 = malloc(sizeof(char) * 32000);
	char *nb_food_str = malloc(sizeof(char) * 5);
	int message_send = 0;

	buff = strdup("Inventory\n");
	if ((message_send = send(fd, buff, strlen(buff), 0)) == -1)
		return (1);
	if (FD_ISSET(fd, &rdfs)) {
		if ((message_send = recv(fd, buf1, 32000 - 1, 0)) == -1)
			return (1);
		else
			buf1[message_send - 1] = '\0';
	}
	check_elevation(buf1, nb_food_str, fd, rdfs);
	(void)(act);
	forward(fd, rdfs);
	return (2);
}
