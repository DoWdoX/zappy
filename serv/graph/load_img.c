/*
** EPITECH PROJECT, 2018
** load_img.c
** File description:
** 
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface	*load_image(char *filename)
{
	SDL_Surface *loaded_img = NULL;
	SDL_Surface *optimized_img = NULL;

	loaded_img = SDL_LoadBMP(filename);
	if (loaded_img) {
		optimized_img = SDL_DisplayFormat(loaded_img);
		SDL_FreeSurface(loaded_img);
	}
	return (optimized_img);
}

SDL_Surface	*load_image_png(char *filename)
{
	SDL_Surface *loaded_img = NULL;

	loaded_img = IMG_Load(filename);
	return (loaded_img);
}
