SRCS		= main.c mini_utils.c \
				parse_map/parse_map.c parse_map/ft_split_for_parse.c \
				bin/exit_utils.c bin/main_game.c  bin/mini_utils_game.c \
				bin/draw_utils.c bin/prepare.c bin/game_play.c bin/hook_utils.c

OBJS		= ${SRCS:.c=.o}

HEAD		= so_long.h

NAME		= so_long

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

LIBS		= -L /usr/lib -lmlx -lXext -lX11

%.o:	%.c ${HEAD}
		${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
