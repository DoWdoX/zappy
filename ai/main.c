/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** 
*/

#include "ai.h"

int	connecting_to_server(int fd, char *tname)
{
	char *buf = malloc(sizeof(char) * 32000);

	bzero(buf, 32000);
	read(fd, buf, 32000);
	if (strcmp(buf, "WELCOME\n") == 0) {
		write(0, buf, strlen(buf));
		write(fd, tname, strlen(tname));
	}
	bzero(buf, 32000);
	read(fd, buf, 32000 - 1);
	printf("%s\n", buf);
	if (strncmp(buf, "ko", 2) == 0)
		return (1);
	return (0);
}

int	launch(int port, struct hostent *host, char *tname)
{
	int fd;
	struct sockaddr_in s_in;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd == -1)
		return (1);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr = *(struct in_addr *)host->h_addr;
	if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1) {
		if (close(fd) == -1)
			return (1);
		return (1);
	}
	connect(fd, (struct sockaddr *)&s_in, sizeof(s_in));
	if ((connecting_to_server(fd, tname)) == 0) {
		if (emitting_and_receiving(fd) == -1 && close(fd) == -1)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int port;
	struct hostent *host = NULL;
	char *tname;
	int i = 1;

	while (i < ac - 1) {
		if (av[i] && av[i + 1] && strcmp(av[i], "-p") == 0)
			port = atoi(av[i + 1]);
		if (av[i] && av[i + 1] && strcmp(av[i], "-h") == 0)
			host = gethostbyname(av[i + 1]);
		if (av[i] && av[i + 1] && strcmp(av[i], "-n") == 0)
			tname = strdup(av[i + 1]);
		i++;
	}
	if (port && host) {
		if (launch(port, host, tname) == -1)
			return (-1);
	}
	return (0);
}
