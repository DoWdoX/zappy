/*
** EPITECH PROJECT, 2018
** actions_handling.c
** File description:
** 
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "serv.h"

int	count_actions(client_t *active)
{
	aq_t *tmp = active->actions_queue;
	int count = 1;

	if (!active->action)
		return (0);
	while (tmp) {
		++count;
		tmp = tmp->next;
	}
	return (count);
}

void	next_action(client_t *client)
{
	if (client->actions_queue) {
		client->action = client->actions_queue->action;
		client->time_action = get_action_time(client->action);
		client->actions_queue = client->actions_queue->next;
	} else {
		client->action = NULL;
		client->time_action = -1;
	}
}

void	add_to_action_queue(client_t *active, char *command)
{
	aq_t *new_action = malloc(sizeof(aq_t));
	aq_t *tmp = active->actions_queue;

	if (!active->action) {
		active->action = command;
		active->time_action = get_action_time(command);
		return;
	}
	if (count_actions(active) >= 10 || !new_action)
		return;
	new_action->action = command;
	new_action->next = NULL;
	if (!active->actions_queue)
		active->actions_queue = new_action;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_action;
	}
}
