/*
** EPITECH PROJECT, 2018
** funcptr
** File description:
** zappy
*/

#include "serv.h"

#ifndef FUNCPTR_H_
# define FUNCPTR_H_

# define NB_MOD 12

typedef struct s_funcptr_tab {
	char *buf;
	int (*funcptr)(int fd, char *buf, client_t *client, gmap_t *map);
} t_funcptr_tab;

int mod_fwd(int, char *, client_t *, gmap_t *);
int mod_right(int, char *, client_t *, gmap_t *);
int mod_left(int, char *, client_t *, gmap_t *);
int mod_look(int, char *, client_t *, gmap_t *);
int mod_talk(int, char *, client_t *, gmap_t *);
int mod_fork(int, char *, client_t *, gmap_t *);
int mod_take(int, char *, client_t *, gmap_t *);
int mod_set(int, char *, client_t *, gmap_t *);
int mod_eject(int, char *, client_t *, gmap_t *);
int mod_elevate(int, char *, client_t *, gmap_t *);
int mod_connect_nbr(int, char *, client_t *, gmap_t *);
int mod_inventory(int, char *, client_t *, gmap_t *);

typedef struct s_funcptr_take {
	char *buf;
	int (*funcptr)(int fd, client_t *client, map_t *ch);
} t_funcptr_take;

int take_linemate(int, client_t *, map_t *);
int take_deraumere(int, client_t *, map_t *);
int take_sibur(int, client_t *, map_t *);
int take_mendiane(int, client_t *, map_t *);
int take_phiras(int, client_t *, map_t *);
int take_thystam(int, client_t *, map_t *);
int take_food(int, client_t *, map_t *);

typedef struct s_funcptr_set {
	char *buf;
	int (*funcptr)(int fd, client_t *client, map_t *ch);
} t_funcptr_set;

int set_linemate(int, client_t *, map_t *);
int set_deraumere(int, client_t *, map_t *);
int set_sibur(int, client_t *, map_t *);
int set_mendiane(int, client_t *, map_t *);
int set_phiras(int, client_t *, map_t *);
int set_thystam(int, client_t *, map_t *);
int set_food(int, client_t *, map_t *);

typedef struct s_dirptr {
	direction dir;
	void (*fptr)(client_t *client, gmap_t *map);
} t_dirptr;

void move_up(client_t *, gmap_t *);
void move_down(client_t *, gmap_t *);
void move_left(client_t *, gmap_t *);
void move_right(client_t *, gmap_t *);

void look_up(int, gmap_t *, client_t *, map_t **);
void look_down(int, gmap_t *, client_t *, map_t **);
void look_left(int, gmap_t *, client_t *, map_t **);
void look_right(int, gmap_t *, client_t *, map_t **);

#endif /* !FUNCPTR_H_ */
