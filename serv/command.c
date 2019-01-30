/*
** EPITECH PROJECT, 2018
** command
** File description:
** zappy
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "funcptr.h"
#include "serv.h"

extern t_funcptr_tab g_tab[];

char *get_command(char *buf)
{
	char *command = malloc(sizeof(char) * 32000);
	int i = 0;
	int j = 0;

	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	while (buf[i]) {
		if (buf[i] != ' ')
			command[j++] = buf[i++];
		else if (buf[i] == ' ') {
			command[j] = '\0';
			return (command);
		}
	}
	return (command);
}

int analyse_command(char *buf, client_t *client, int fd, gmap_t *map)
{
	int i = 0;

	while (i < NB_MOD) {
		printf("buf -> |%s|\n tab -> |%s|\n", buf, g_tab[i].buf);
		if (strncmp(buf, g_tab[i].buf, strlen(g_tab[i].buf)) == 0) {
			g_tab[i].funcptr(fd, buf, client, map);
			return (0);
		}
		i += 1;
	}
	if (i == NB_MOD)
		write(fd, "ko\n", 3);
	return (0);
}
