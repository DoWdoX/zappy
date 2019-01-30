/*
** EPITECH PROJECT, 2018
** tests_init.c
** File description:
** 
*/

#include <string.h>
#include <stdlib.h>
#include "serv.h"

client_t	*init_test_client(void)
{
	client_t *active = malloc(sizeof(client_t));
	char *cmd1 = strdup("Potatoe pc");
	char *cmd2 = strdup("Chmod 777 your mom");
	char *cmd3 = strdup("Test: icals");

	add_to_action_queue(active, cmd1);
	add_to_action_queue(active, cmd2);
	add_to_action_queue(active, cmd3);
	return (active);
}

char	**init_test_av(int *test_ac)
{
	char **test_av = malloc(sizeof(char *) * 32000);

	test_av[(*test_ac)++] = strdup("./a.out");
	test_av[(*test_ac)++] = strdup("-p");
	test_av[(*test_ac)++] = strdup("4242");
	test_av[(*test_ac)++] = strdup("-x");
	test_av[(*test_ac)++] = strdup("21");
	test_av[(*test_ac)++] = strdup("-c");
	test_av[(*test_ac)++] = strdup("5");
	test_av[(*test_ac)++] = strdup("-n");
	test_av[(*test_ac)++] = strdup("Blue");
	test_av[(*test_ac)++] = strdup("Red");
	test_av[(*test_ac)++] = strdup("-f");
	test_av[(*test_ac)++] = strdup("3");
	return (test_av);
}
