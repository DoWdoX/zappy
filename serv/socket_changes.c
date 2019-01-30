/*
** EPITECH PROJECT, 2018
** sokcet_changes.c
** File description:
** 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include "serv.h"

static void set_fds(int *fd, fd_set *readfds, client_t *client)
{
	client_t *tmp = client;

	FD_ZERO(readfds);
	FD_SET(*fd, readfds);
	while (tmp != NULL) {
		FD_SET(tmp->client_fd, *(&readfds));
		tmp = tmp->next;
	}
}

static int find_biggest_fd(client_t *client, int fd)
{
	client_t *tmp = client;
	int res = 0;

	while (tmp) {
		if (tmp->client_fd > res)
			res = tmp->client_fd;
		tmp = tmp->next;
	}
	if (fd > res)
		res = fd;
	return (res);
}

int receiving_and_emitting(client_t *client, client_t *active)
{
	int len1 = 0;
	char *buf = malloc(sizeof(char) * 32000);
	char **tab;
	int i = 0;

	(void)(client);
	bzero(buf, 32000);
	len1 = read(active->client_fd, buf, 32000);
	if (len1 <= 0)
		return (-1);
	tab = str_wordtab(buf);
	while (tab && tab[i + 1]) {
		add_to_action_queue(active, tab[i]);
		i++;
	}
	return (0);
}

int isset_fd_client(client_t *client, fd_set readfds)
{
	client_t *tmp = client;

	while (tmp != NULL) {
		if ((FD_ISSET(tmp->client_fd, &readfds)) != 0)
			receiving_and_emitting(client, tmp);
		tmp = tmp->next;
	}
	return (0);
}

int catch_socket_changes(int fd, client_t **client, int *nbc, gmap_t *gmap)
{
	struct sockaddr_in inc;
	socklen_t size;
	fd_set readfds;
	int err;
	int cfd;
	struct timeval tv;

	tv.tv_sec = 0;
	tv.tv_usec = 10;
	set_fds(&fd, &readfds, *client);
	cfd = find_biggest_fd(*client, fd) + 1;
	err = select(cfd, &readfds, NULL, NULL, &tv);
	isset_fd_client(*client, readfds);
	if (FD_ISSET(fd, &readfds) != 0) {
		cfd = accept(fd, (struct sockaddr *)&inc, &size);
		if (cfd == -1)
			write(cfd, "ko\n", 3);
		else
			creation(cfd, nbc, client, gmap);
	}
	return (err);
}
