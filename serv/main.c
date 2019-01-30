/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** 
*/

#include <unistd.h>
#include <signal.h>
#include "serv.h"
#include "graphical.h"

static int	loop(int fd, gmap_t *gmap, int freq)
{
	graph_t *g = init_graph(gmap);
	client_t *client = NULL;
	int nb_clients = 0;
	int err = 0;

	while (err != -1) {
		err = catch_socket_changes(fd, &client, &nb_clients, gmap);
		if (events_handling(g, gmap->width, gmap->height) == -1)
			break;
		if (timer(freq)) {
			turn(&client, gmap);
			print_map_graph(g, gmap, client);
		}
	}
	destroy_graph(g);
	return (0);
}

int	main(int ac, char **av)
{
	params_t p;
	gmap_t gmap;
	int fd;

	p.freq = 100;
	if (get_params(ac, av, &p))
		return (84);
	fd = create_server_socket(p.port);
	gmap = init_map(p.height, p.width);
	gmap.tnames = p.tnames;
	gmap.client_nb = p.client_nb;
	gmap.nb_teams = p.nb_teams;
	if (fd == -1 || !gmap.map)
		return (84);
	if (loop(fd, &gmap, p.freq) == -1)
		return (84);
	if (close(fd) == -1)
		return (84);
	return (0);
}
