/*
** EPITECH PROJECT, 2018
** serv
** File description:
** zappy
*/

#ifndef SERV_H
# define SERV_H

# include <time.h>
# include "graphical.h"

typedef struct {
	int port;
	int width;
	int height;
	char **tnames;
	int nb_teams;
	int client_nb;
	int freq;
} params_t;

typedef struct aq_s {
	char *action;
	struct aq_s *next;
} aq_t;

typedef struct {
	int linemate;
	int deraumere;
	int sibur;
	int mendiane;
	int phiras;
	int thystam;
} stones_t;

typedef struct incantation_s {
	stones_t stones;
	int players;
} incantation_t;

typedef enum {
	TOP,
	RIGHT,
	DOWN,
	LEFT
} direction;

typedef struct characters_s {
	int client_fd;
	int x;
	int y;
	direction direction;
	char *team;
	int food;
	int hungryness;
	stones_t stones;
	int elevation;
	struct characters_s *map_next;
} characters_t;

typedef struct client_s {
	int client_fd;
	char *team;
	char *action;
	int alive;
	int time_action;
	aq_t *actions_queue;
	characters_t *players;
	struct client_s *next;
	struct client_s *prev;
} client_t;

typedef struct {
	characters_t *ch;
	int food;
	stones_t stones;
} map_t;

typedef struct {
	map_t **map;
	int height;
	int width;
	char **tnames;
	int nb_teams;
	int client_nb;
} gmap_t;

//main.c
int main(int, char **);
//command.c
int analyse_command(char *, client_t *, int, gmap_t *);
char *get_command(char *);
//params.c
int get_params(int, char **, params_t *);
//serv_socket.c
int create_server_socket(int);
//map.c
void print_map(client_t *, gmap_t *);
gmap_t init_map(int, int);
void add_player_on_map(gmap_t *, characters_t *);
void sub_player_on_map(gmap_t *, characters_t *);
//socket_changes.c
int catch_socket_changes(int, client_t **, int *, gmap_t *);
//client.c
int create(int, client_t **, int, gmap_t *);
//player.c
char print_player(characters_t *);
characters_t *add_player_on_client(client_t *, gmap_t *);
//stones.c
int my_rand_stones(int);
stones_t init_rand_stones(void);
stones_t init_stones(void);
//actions_handling.c
void next_action(client_t *);
int count_actions(client_t *);
void add_to_action_queue(client_t *, char *);
//actions_time.c
int get_action_time(const char *);
//turn.c
void turn(client_t **, gmap_t *);
//str_to_wordtab.c
char **str_wordtab(char *);
//wordtab.c
int nbr_word(char *);
char **wordtab(char *, int);
//timer.c
int timer(int);
//events.c
int events_handling(graph_t *, int, int);
//look.c
char *look_food(map_t cha, char *res);
char *look_linemate(map_t cha, char *res);
char *look_deraumere(map_t cha, char *res);
char *look_mendiane(map_t cha, char *res);
char *look_phiras(map_t cha, char *res);
char *look_sibur(map_t cha, char *res);
char *look_thystam(map_t cha, char *res);
char *look_player(characters_t *cho, char *res);

//creation.c
int creation(int, int *, client_t **, gmap_t *);
//elevation.c
incantation_t *level1(void);
incantation_t *level2(void);
incantation_t *level3(void);
incantation_t *level4(void);
incantation_t *level5(void);
incantation_t *level6(void);
incantation_t *level7(void);

//init_graph.c
graph_t	*init_graph(gmap_t *);
void	destroy_graph(graph_t *);
void	apply_surface(int, int, SDL_Surface *, SDL_Surface *);
//graph/map.c
smap_t	*load_map_ressources(void);
void	draw_map_grass(const gmap_t *, SDL_Surface *, const smap_t *);
void	draw_map_cliff(const gmap_t *, SDL_Surface *, const smap_t *);

//load_img.c
SDL_Surface *load_image(char *);
SDL_Surface *load_image_png(char *);
//print_graph.c
void	print_map_graph(graph_t *, gmap_t *, client_t *);
//print_box.c
void	print_mainbox(graph_t *, client_t *, int);
//print_text.c
void	text_printer(graph_t *, char *, int, int);
char	**init_tmp_stones(stones_t *);
void	print_text_stones(graph_t *, stones_t, const int);
void	print_text_head(graph_t *, client_t *, const int);
void	print_text_stats(graph_t *, client_t *, const int);
//print_img.c
void	print_badges(graph_t *, const client_t *, const int);
void	print_img_items(graph_t *, const int);
//print_case.c
void	print_case(graph_t *, gmap_t *);

#endif /* !SERV_H */
