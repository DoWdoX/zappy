/*
** EPITECH PROJECT, 2018
** ai
** File description:
** zappy
*/

#ifndef AI_H
# define AI_H

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

void do_command(int fd, fd_set rdfs, char*);
void forward(int fd, fd_set rdfs);
//fd.c
int fds_isset(fd_set rdfs, int fd);
int fds_set(fd_set *rdfs, int *fd);
int emitting_and_receiving(int fd);
//main.c
int main(int ac, char **av);
int launch(int port, struct hostent *host, char *tname);

#endif /* !AI_H */
