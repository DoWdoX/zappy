/*
** EPITECH PROJECT, 2018
** init_player
** File description:
** zappy
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "serv.h"

char print_player(characters_t *ch)
{
	characters_t *tmp = ch;
	char i = '0';

	while (tmp) {
		tmp = tmp->map_next;
		i++;
	}
	return (i);
}

characters_t *add_player_on_client(client_t *client, gmap_t *map)
{
	characters_t *ch = malloc(sizeof(characters_t));
	time_t t;

	ch->client_fd = client->client_fd;
	ch->team = NULL;
	ch->hungryness = 126;
	ch->elevation = 1;
	ch->food = 9;
	ch->stones = init_stones();
	srand((unsigned) time(&t));
	ch->direction = rand() % 4;
	ch->x = rand() % map->width;
	ch->y = rand() % map->height;
	ch->map_next = NULL;
	client->players = ch;
	printf("x : %d\ny : %d\n", ch->x, ch->y);
	printf("direction : %d\n", ch->direction);
	return (ch);
}
