/*
** EPITECH PROJECT, 2018
** fd
** File description:
** zappy
*/

#include <time.h>
#include "ai.h"

typedef int (*f)(int, int, fd_set);
int hungry(int, int, fd_set);
int take_food(int, int, fd_set);
int elevate(int, int, fd_set);
f ptrActions[] = { hungry, take_food, elevate };

void do_command(int fd, fd_set rdfs, char *str)
{
	int message_send = 0;
	char *buff = malloc(sizeof(char) * 32000);
	buff = strdup(str);
	if ((message_send = send(fd, buff, strlen(buff), 0)) == -1)
		return;
	char *buf1 = malloc(sizeof(char) * 32000);
	if (FD_ISSET(fd, &rdfs)) {
		if ((message_send = recv(fd, buf1, 32000 - 1, 0)) == -1)
			return;
		else
			buf1[message_send - 1] = '\0';
	}
}

int fds_isset(fd_set rdfs, int fd)
{
	int message_send = 0;
	char *buf1 = malloc(sizeof(char) *32000);
	if (FD_ISSET(fd, &rdfs)) {
		if ((message_send = recv(fd, buf1, 32000 - 1, 0)) == -1)
			return (1);
		else {
			buf1[message_send - 1] = '\0';
			printf("Receiving message from server : %s\n", buf1);
		}
	}
	int ret = -1;
	for (int i = 0; i < 3; i += 1) {
		ret = ptrActions[i](ret, fd, rdfs);
		if (ret == 2)
			i = -1;
	}
	return (0);
}

int fds_set(fd_set *rdfs, int *fd)
{
	FD_ZERO(&(*rdfs));
	FD_SET(STDIN_FILENO, &(*rdfs));
	FD_SET((*fd), &(*rdfs));
	return (0);
}

int emitting_and_receiving(int fd)
{
	fd_set rdfs;

	while (42) {
		fds_set(&rdfs, &fd);
		select(fd + 1, &rdfs, NULL, NULL, NULL);
		if ((fds_isset(rdfs, fd)) == -1)
			return (-1);
	}
	close(fd);
	return (0);
}
