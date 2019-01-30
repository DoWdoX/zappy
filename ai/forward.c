/*
** EPITECH PROJECT, 2018
** forward.c
** File description:
** forward
*/

#include <time.h>
#include "ai.h"

void forward(int fd, fd_set rdfs)
{
	time_t timer;
	int random = rand() % 3;

	srand((unsigned) time(&timer));
	switch (random) {
	case 0:
		break;
	case 1:
		do_command(fd, rdfs, "Left\n");
		break;
	case 2:
		do_command(fd, rdfs, "Right\n");
		break;
	};
	do_command(fd, rdfs, "Forward\n");
}
