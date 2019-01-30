/*
** EPITECH PROJECT, 2018
** script
** File description:
** zappy
*/

#include <unistd.h>
#include <stdlib.h>

static int sys_fct_scientifique(pid_t pid)
{
	if (pid == 0) {
		system("./zappy_ai -p 4242 -h localhost -n Scientifique");
		return (0);
	}
	return (0);
}

static int sys_fct_scout(pid_t pid)
{
	if (pid == 0) {
		system("./zappy_ai -p 4242 -h localhost -n Scout");
		return (0);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
	int i = 0;
	pid_t pid = 0;

	while (i != 5) {
		pid = fork();
		sys_fct_scientifique(pid);;
		sleep(1);
		pid = fork();
		sys_fct_scout(pid);;
		sleep(1);
		i++;
	}
}
