/*
** EPITECH PROJECT, 2018
** graphical.h
** File description:
** 
*/

#ifndef GRAPHICAL_H_
# define GRAPHICAL_H_

# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>
# include <SDL/SDL_ttf.h>
# include <SDL/SDL_image.h>

# define TILE_SIZE 32
# define START (2 * TILE_SIZE)
# define START_BOX(width, add) ((width + 4) * TILE_SIZE + add)
# define SCREEN_WIDTH(width) (TILE_SIZE * ((width) + 4) + 350)
# define SCREEN_HEIGHT(height) (TILE_SIZE * ((height) + 5))
# define SCREEN_BPP 32

typedef struct {
	SDL_Surface **grass;
	SDL_Surface *left;
	SDL_Surface *right;
	SDL_Surface *up;
	SDL_Surface *down;
	SDL_Surface *up_left;
	SDL_Surface *up_right;
	SDL_Surface *down_left;
	SDL_Surface *down_right;
} smap_t;

typedef struct {
	SDL_Surface *screen;
	SDL_Surface **balls;
	SDL_Surface *food;
	SDL_Surface *mainbox;
	SDL_Surface **badges;
	SDL_Event event;
	Mix_Music *music;
	Mix_Chunk **screams;
	TTF_Font *ttlfont;
	TTF_Font *coordfont;
	TTF_Font *basefont;
	SDL_Color color;
	smap_t *smap;
	SDL_Surface *mark;
	int x_detail;
	int y_detail;
	int selected;
} graph_t;

# define PATH_FONT "assets/pokemon_font.ttf"

# define PATH_SONG "assets/sounds/road1.wav"
# define PATH_EGG_P03 "assets/sounds/Cri_4_d_003.wav"
# define PATH_EGG_P06 "assets/sounds/Cri_4_d_006.wav"
# define PATH_EGG_P09 "assets/sounds/Cri_4_d_009.wav"
# define PATH_EGG_P25 "assets/sounds/Cri_4_d_025.wav"

# define PATH_GRASS_0 "assets/map/grass/grass0.bmp"
# define PATH_GRASS_1 "assets/map/grass/grass1.bmp"
# define PATH_GRASS_2 "assets/map/grass/grass2.bmp"
# define PATH_GRASS_3 "assets/map/grass/grass3.bmp"
# define PATH_GRASS_4 "assets/map/grass/grass4.bmp"
# define PATH_GRASS_5 "assets/map/grass/grass5.bmp"

# define PATH_LEFT "assets/map/corners/left.bmp"
# define PATH_RIGHT "assets/map/corners/right.bmp"
# define PATH_UP "assets/map/corners/up.bmp"
# define PATH_DOWN "assets/map/corners/down.bmp"
# define PATH_UP_LEFT "assets/map/corners/cornerUpLeft.bmp"
# define PATH_UP_RIGHT "assets/map/corners/cornerUpRight.bmp"
# define PATH_DOWN_LEFT "assets/map/corners/cornerDownLeft.bmp"
# define PATH_DOWN_RIGHT "assets/map/corners/cornerDownRight.bmp"

# define PATH_TRAINER "assets/trainers/"

# define PATH_FOOD "assets/items/moomoomilk.png"
# define PATH_LINEMATE "assets/items/pokeball.png"
# define PATH_DERAUMERE "assets/items/superball.png"
# define PATH_SIBUR "assets/items/hyperball.png"
# define PATH_MENDIANE "assets/items/sombreball.png"
# define PATH_PHIRAS "assets/items/safariball.png"
# define PATH_THYSTAM "assets/items/masterball.png"

# define PATH_BADGE_1 "assets/badges/badge1.png"
# define PATH_BADGE_2 "assets/badges/badge2.png"
# define PATH_BADGE_3 "assets/badges/badge3.png"
# define PATH_BADGE_4 "assets/badges/badge4.png"
# define PATH_BADGE_5 "assets/badges/badge5.png"
# define PATH_BADGE_6 "assets/badges/badge6.png"
# define PATH_BADGE_7 "assets/badges/badge7.png"
# define PATH_BADGE_8 "assets/badges/badge8.png"

# define PATH_MAINBOX "assets/infowindow/mainbox.png"
# define PATH_MARK "assets/infowindow/mark.png"

#endif /* ! GRAPHICAL_H_ */
