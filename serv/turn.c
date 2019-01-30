/*
** EPITECH PROJECT, 2018
** turn.c
** File description:
** 
*/

#include <unistd.h>
#include "serv.h"

static void starvation(client_t **tmp)
{
	if ((*tmp)->players->hungryness == 0) {
		if ((*tmp)->players->food >= 1) {
			(*tmp)->players->food -= 1;
			(*tmp)->players->hungryness = 126;
		}
		else {
			write((*tmp)->client_fd, "dead\n", 5);
			(*tmp)->alive = 0;
		}
	}
}

static stones_t update_rand_stones(stones_t st)
{
	st.linemate = st.linemate + my_rand_stones(6000);
	st.deraumere = st.deraumere + my_rand_stones(6000);
	st.sibur = st.sibur + my_rand_stones(6000);
	st.mendiane = st.mendiane + my_rand_stones(6000);
	st.phiras = st.phiras + my_rand_stones(8000);
	st.thystam = st.thystam + my_rand_stones(10000);
	return (st);
}

static map_t upm(map_t map)
{
	map.food = map.food + my_rand_stones(600);
	map.stones = update_rand_stones(map.stones);
	return (map);
}

void spawn_new_ressources(gmap_t **gmap)
{
	for (int j = 0; (*gmap)->map && j < (*gmap)->height; ++j) {
		for (int i = 0; (*gmap)->map[j] && i < (*gmap)->width; ++i)
			(*gmap)->map[j][i] = upm((*gmap)->map[j][i]);
	}
}

void turn(client_t **client, gmap_t *gmap)
{
	client_t *tmp = *client;
	int fd;

	while (tmp) {
		fd = tmp->client_fd;
		if (tmp->time_action == 0 && tmp->action && tmp->alive == 1) {
			analyse_command(tmp->action, tmp, fd, gmap);
			next_action(tmp);
		}
		else if (tmp->action)
			tmp->time_action -= 1;
		tmp->players->hungryness -= 1;
		starvation(&tmp);
		tmp = tmp->next;
	}
	spawn_new_ressources(&gmap);
}
