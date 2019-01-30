/*
** EPITECH PROJECT, 2018
** str_to_wordtab.c
** File description:
** str_to_wordtab
*/

#include "serv.h"

char	**str_wordtab(char *str)
{
	char **tab;
	int hor;

	hor = nbr_word(str);
	tab = wordtab(str, hor);
	return (tab);
}
