##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## 
##

SVDIR	=	./serv
GRAPH	=	graph
MOD	=	mods
LOOK	=	look
ELEVATE	=	elevation
TAKE	=	take
SET	=	set
AIDIR	=	./ai
TDIR	=	./tests

SVNAME	=	zappy_server
AINAME	=	zappy_ai
NOAINAME =	zappy_noai

SVSRCS	=	$(SVDIR)/main.c			\
		$(SVDIR)/serv_socket.c		\
		$(SVDIR)/socket_changes.c	\
		$(SVDIR)/client.c		\
		$(SVDIR)/map.c			\
		$(SVDIR)/stones.c		\
		$(SVDIR)/players.c		\
		$(SVDIR)/usage.c		\
		$(SVDIR)/params.c		\
		$(SVDIR)/actions_handling.c	\
		$(SVDIR)/actions_time.c		\
		$(SVDIR)/turn.c			\
		$(SVDIR)/str_to_wordtab.c	\
		$(SVDIR)/wordtab.c		\
		$(SVDIR)/timer.c		\
		$(SVDIR)/funcptr.c		\
		$(SVDIR)/command.c		\
		$(SVDIR)/fget_params.c		\
		$(SVDIR)/fget_names.c		\
		$(SVDIR)/creation.c		\
		$(SVDIR)/$(GRAPH)/init_graph.c	\
		$(SVDIR)/$(GRAPH)/map.c		\
		$(SVDIR)/$(GRAPH)/load_img.c	\
		$(SVDIR)/$(GRAPH)/print_graph.c	\
		$(SVDIR)/$(GRAPH)/events.c	\
		$(SVDIR)/$(GRAPH)/print_box.c	\
		$(SVDIR)/$(GRAPH)/print_text.c	\
		$(SVDIR)/$(GRAPH)/print_case.c	\
		$(SVDIR)/$(GRAPH)/print_img.c	\
		$(SVDIR)/$(MOD)/mod_connect.c	\
		$(SVDIR)/$(MOD)/mod_direction.c	\
		$(SVDIR)/$(MOD)/mod_elevate.c	\
		$(SVDIR)/$(MOD)/mod_fork.c	\
		$(SVDIR)/$(MOD)/mod_fwd.c	\
		$(SVDIR)/$(MOD)/mod_look.c	\
		$(SVDIR)/$(MOD)/mod_eject.c	\
		$(SVDIR)/$(MOD)/mod_objs.c	\
		$(SVDIR)/$(MOD)/mod_talk.c	\
		$(SVDIR)/$(MOD)/$(TAKE)/take_linemate.c		\
		$(SVDIR)/$(MOD)/$(TAKE)/take_deraumere.c	\
		$(SVDIR)/$(MOD)/$(TAKE)/take_sibur.c		\
		$(SVDIR)/$(MOD)/$(TAKE)/take_mendiane.c		\
		$(SVDIR)/$(MOD)/$(TAKE)/take_phiras.c		\
		$(SVDIR)/$(MOD)/$(TAKE)/take_thystam.c		\
		$(SVDIR)/$(MOD)/$(TAKE)/take_food.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_linemate.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_deraumere.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_sibur.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_mendiane.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_phiras.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_thystam.c		\
		$(SVDIR)/$(MOD)/$(SET)/set_food.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level1.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level2.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level3.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level4.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level5.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level6.c		\
		$(SVDIR)/$(MOD)/$(ELEVATE)/level7.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_linemate.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_deraumere.c	\
		$(SVDIR)/$(MOD)/$(LOOK)/look_sibur.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_mendiane.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_phiras.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_thystam.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_food.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_player.c		\
		$(SVDIR)/$(MOD)/$(LOOK)/look_direction.c

AISRCS	=	$(AIDIR)/main.c			\
		$(AIDIR)/fd.c			\
		$(AIDIR)/take_food.c		\
		$(AIDIR)/elevate.c		\
		$(AIDIR)/hungry.c		\
		$(AIDIR)/forward.c

NOAISRCS  =     $(AIDIR)/main.c                 \
		$(AIDIR)/fd_noia.c

TESTSRCS =	$(TDIR)/tests.c			\
		$(TDIR)/tests_inits.c		\
		$(SVDIR)/actions_handling.c	\
		$(SVDIR)/actions_time.c		\
		$(SVDIR)/params.c		\
		$(SVDIR)/fget_params.c		\
		$(SVDIR)/fget_names.c		\
		$(SVDIR)/usage.c


SVOBJS =	$(SVSRCS:.c=.o)
AIOBJS =	$(AISRCS:.c=.o)
NOAIOBJS =	$(NOAISRCS:.c=.o)


RM	=	rm -rf

CFLAGS	+=	-W -Wall -Werror -Wextra
CPPFLAGS +=	-I./inc
LSDL	=	-lSDL -lSDLmain -lSDL_mixer -lSDL_image -lSDL_ttf
CRIT	=	-lcriterion

all	:	$(SVNAME) $(AINAME) $(NOAINAME)

$(SVNAME) :	$(SVOBJS)
		gcc -o $(SVNAME) $(SVOBJS) $(LSDL)

$(AINAME) :	$(AIOBJS)
		gcc -o $(AINAME) $(AIOBJS)

$(NOAINAME) :	$(NOAIOBJS)
		gcc -o $(NOAINAME) $(NOAIOBJS)

tests_run :
		gcc $(TESTSRCS) $(CRIT) $(CPPFLAGS)

clean	:
		$(RM) $(SVOBJS) $(AIOBJS) $(NOAIOBJS)

fclean	:	clean
		$(RM) $(SVNAME) $(AINAME) $(NOAINAME)

re	:	fclean all

.PHONY	:	all clean fclean re
