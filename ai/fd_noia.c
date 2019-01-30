/*
** EPITECH PROJECT, 2018
** fd
** File description:
** zappy
*/

#include <time.h>
#include <ctype.h>
#include "ai.h"

static char *backslash(char *res, int j)
{
	res[j] = '\0';
	return (res);
}

static char *capitalize(char *buf)
{
	char *res = malloc(sizeof(char) * 32000);
	int i = 0;
	int j = 0;

	while (buf[i] && (buf[i] == ' ' || buf[i] == '\t'))
		i++;
	if (buf[i] == '/') {
		i++;
		while (buf[i] && (buf[i] != ' ' && buf[i] != '\t')) {
			res[j] = toupper(buf[i]);
			j++;
			i++;
		}
		while (buf[i]) {
			res[j] = (buf[i]);
			j++;
			i++;
		}
		return (backslash(res, j));
	}
	return (buf);
}

int fds_isset(fd_set rdfs, int fd)
{
	int message_send;
	char *buf = malloc(sizeof(char) * 32000);

	if (FD_ISSET(STDIN_FILENO, &rdfs)) {
		fgets(buf, 32000 - 1, stdin);
		buf = capitalize(buf);
		if ((message_send = send(fd, buf, strlen(buf), 0)) == -1)
			return (1);
	}
	else if (FD_ISSET(fd, &rdfs)) {
		if ((message_send = recv(fd, buf, 32000 - 1, 0)) == -1)
			return (1);
		else {
			printf("Réception !\n");
			buf[message_send - 1] = '\0';
			printf("%s\n", buf);
		}
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
