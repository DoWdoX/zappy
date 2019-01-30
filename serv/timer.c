/*
** EPITECH PROJECT, 2018
** timer.c
** File description:
** 
*/

#include <sys/timeb.h>

int	timer(int i)
{
	static struct timeb tim1;
	static float nb = 0;
	struct timeb tim3;
	float f = 1 / (float)i;

	ftime(&tim3);
	if (tim1.millitm != tim3.millitm) {
		tim1.millitm = tim3.millitm;
		nb += 0.001;
		if (nb >= f) {
			nb = 0;
			return (1);
		}
	}
	return (0);
}
