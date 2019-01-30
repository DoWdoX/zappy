/*
** EPITECH PROJECT, 2018
** fptrtab.h
** File description:
** 
*/

#ifndef FPTRTAB_H_
# define FPTRTAB_H_

# include "serv.h"

typedef struct {
	char *cmp;
	int (*f)(int, char **, int *, params_t *);
	int set;
} fptrtab_t;

int	usage(char *);

int	fget_port(int, char **, int *, params_t *);
int	fget_width(int, char **, int *, params_t *);
int	fget_height(int, char **, int *, params_t *);
int	fget_names(int, char **, int *, params_t *);
int	fget_cli_nb(int, char **, int *, params_t *);
int	fget_freq(int, char **, int *, params_t *);

#endif /* !FPTRTAB_H_ */
