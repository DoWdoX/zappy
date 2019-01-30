/*
** EPITECH PROJECT, 2018
** wordtab
** File description:
** irc
*/

#include <stdlib.h>
#include "serv.h"

int nbr_word2(int a, char *str)
{
	while (str[a] != '\0' && str[a] == '\n')
		a = a + 1;
	return (a);
}

int nbr_word(char *str)
{
	int a = 0;
	int n = 0;

	while (str[a] != '\0') {
		if (str[a] == '\n') {
			a = nbr_word2(a, str);
			n = n + 1;
		}
		a = a + 1;
	}
	if (str[a - 1] != '\n')
		n = n + 1;
	return (n);
}

int nbr_char(char *str, int count)
{
	int a = count;
	int n = 0;

	while (str[a] != '\0' && (!(str[a] == '\n'))) {
		a = a + 1;
		n = n + 1;
	}
	return (n);
}

void word(int c, int *a, char *str, char **tab)
{
	int b = 0;
	int ver = nbr_char(str, *a);

	if ((tab[c] = malloc(ver + 1)) == NULL)
		return;
	while (b < ver) {
		tab[c][b] = str[*a];
		b = b + 1;
		(*a) = (*a) + 1;
	}
	tab[c][b] = '\0';
	while (str[*a] != '\0' && str[*a] == '\n')
		(*a)++;
}

char **wordtab(char *str, int hor)
{
	char **tab = malloc(sizeof(char **) * (hor + 1));
	int b = 0;
	int a = 0;

	if (tab == NULL)
		return (NULL);
	while (b < hor) {
		word(b, &a, str, tab);
		b = b + 1;
	}
	tab[b] = '\0';
	return (tab);
}
