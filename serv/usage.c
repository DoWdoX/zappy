/*
** EPITECH PROJECT, 2018
** usage.c
** File description:
** 
*/

#include <stdio.h>

int	usage(char *bin)
{
	printf("USAGE: %s -p port -x width -y height", bin);
	printf(" -n name1 name2 ... -c clientsNb -f freq\n");
	printf("port is the port number\n");
	printf("width is the width of the world\n");
	printf("height is the height of the world\n");
	printf("nameX is the name of the team X\n");
	printf("clientsNb is the number of authorized clients per team\n");
	printf("freq is the reciprocal of time unit for execution of ");
	printf("actions\n");
	return (1);
}
