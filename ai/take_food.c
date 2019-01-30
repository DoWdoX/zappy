/*
** EPITECH PROJECT, 2018
** take_food.c
** File description:
** take_food
*/

#include <time.h>
#include "ai.h"

int	take_food(int act, int fd, fd_set rdfs)
{
	int message_send = 0;

	if (act != 1)
		return (1);
	char *buff = malloc(sizeof(char) * 32000);
	buff = strdup("Take food\n");
	if ((message_send = send(fd, buff, strlen(buff), 0)) == -1)
		return (-1);
	char *buf1 = malloc(sizeof(char) * 32000);
	if (FD_ISSET(fd, &rdfs)) {
		if ((message_send = recv(fd, buf1, 32000 - 1, 0)) == -1)
			return (-1);
		else
			buf1[message_send - 1] = '\0';
	}
	if (strncmp(buf1, "ko", 2) == 0)
		forward(fd, rdfs);
	return (1);
}
