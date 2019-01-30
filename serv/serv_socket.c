/*
** EPITECH PROJECT, 2018
** serv_socket.c
** File description:
** 
*/

#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "serv.h"

static int	close_and_return(int fd, int ret)
{
	if (close(fd) == -1)
		return (-1);
	return (ret);
}

int	create_server_socket(int port)
{
	struct protoent *pe = getprotobyname("TCP");
	struct sockaddr_in s_in;
	int fd;

	if (!pe)
		return (-1);
	fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
	if (fd == -1)
		return (-1);
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
		return (close_and_return(fd, -1));
	if (listen(fd, 42) == -1)
		return (close_and_return(fd, -1));
	return (fd);
}
