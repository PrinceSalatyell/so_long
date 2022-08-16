# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:36:16 by josanton          #+#    #+#              #
#    Updated: 2022/08/16 21:56:38 by salatiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== ONLY COMPILES ON MACS ====================================

# COMPILATION VARS

SRCS	=	so_long.c

OBJS	=	${SRCS:.c=.o}

NAME	=	so_long

UNAME	=	${shell uname}

#DIRECTORIES

LIBFT_DIR	=	libft/

MLX_DIR	=	mlx/

MLX_LINUX_DIR	=	mlx_linux/

#GCC & FLAGS

CC	=	gcc

42FLAGS	=	-Wall -Wextra -Wextra

GCC	=	${CC} ${42FLAGS}

#CLEAN

RM	=	rm -f

#COMPILE FOR DIFFERENT MACHINES

ifeq (${UNAME}, Darwin)
#mac
	MLX=-L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit
else
#Linux and others...
	MLX=-Ilibft/ -Imlx_linux/ -L${LIBFT_DIR} -lft -L${MLX_LINUX_DIR} -lmlx -L/usr/lib/ -lXext -lX11 -lm -lz
endif

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# +*+*+**++*+*+*+*+*+*+**+ RULES ++*+**+**++*+*+*+*+*+*+*+*+*+

all:	${NAME} | submodule

${NAME}:	${OBJS} mlx_linux/libmlx.a libft/libft.a
	@${GCC} -o ${NAME} ${OBJS} ${MLX}
	@echo "${COLOUR_GREEN} >>> SO_LONG OK <<< ${COLOUR_END}"

submodule:
	@git submodule update --init --recursive

%.o: %.c
	@${CC} ${42FLAGS} -I mlx_linux -c $< -o $@

libft/libft.a:
	@make -s -C ${LIBFT_DIR}

mlx_linux/libmlx.a:
	@make -s -C ${MLX_LINUX_DIR}
	@echo "${COLOUR_GREEN} >>> MLX OK <<< ${COLOUR_END}"

clean:
	@${MAKE} clean -C ${LIBFT_DIR}
	@${MAKE} clean -C ${MLX_LINUX_DIR}
	@echo "${COLOUR_YELLOW} >>> OBJS CLEANED <<< ${COLOUR_END}"

fclean:		clean
	@${MAKE} fclean -C ${LIBFT_DIR}
	@${RM} ${NAME}
	@echo "${COLOUR_YELLOW} >>> ALL CLEANED <<< ${COLOUR_END}"

re:	fclean all

.PHONY:	all clean fclean re libft submodule mlx
