/*
** EPITECH PROJECT, 2018
** funcptr
** File description:
** zappy
*/

#include "funcptr.h"
#include "serv.h"

t_funcptr_tab g_tab[NB_MOD] =
{
	{"Forward", mod_fwd},
	{"Right", mod_right},
	{"Left", mod_left},
	{"Look", mod_look},
	{"Broadcast", mod_talk},
	{"Fork", mod_fork},
	{"Take", mod_take},
	{"Set", mod_set},
	{"Incantation", mod_elevate},
	{"Connect_nbr", mod_connect_nbr},
	{"Inventory", mod_inventory},
	{"Eject", mod_eject}
};

t_funcptr_take g_ta [7] =
{
	{"linemate", take_linemate},
	{"deraumere", take_deraumere},
	{"sibur", take_sibur},
	{"mendiane", take_mendiane},
	{"phiras", take_phiras},
	{"thystam", take_thystam},
	{"food", take_food}
};

t_funcptr_take g_set [7] =
{
	{"linemate", set_linemate},
	{"deraumere", set_deraumere},
	{"sibur", set_sibur},
	{"mendiane", set_mendiane},
	{"phiras", set_phiras},
	{"thystam", set_thystam},
	{"food", set_food}
};

t_dirptr g_dir[4] =
{
	{TOP, move_up},
	{DOWN, move_down},
	{RIGHT, move_right},
	{LEFT, move_left}
};

