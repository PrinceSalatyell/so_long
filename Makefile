# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: easybreezy <easybreezy@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:36:16 by josanton          #+#    #+#              #
#    Updated: 2022/06/29 19:50:56 by easybreezy       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== ONLY COMPILES ON MACS ====================================

# COMPILATION VARS

SRCS	=	so_long.c

NAME	=	so_long

UNAME	=	${shell uname}

#DIRECTORIES

LIBFT_DIR	=	libft/

MLX_DIR	=	mlx/

MLX_LINUX_DIR	=	mlx_linux/

#GCC & FLAGS

COMPILER	=	gcc

42FLAGS	=	-Wall -Wextra -Wextra

LIBFLAGS =	-L${LIBFT_DIR} -lft

MLXFLAGS =	-Imlx -L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

MLXFLAGS_LINUX	=	-I/usr/include -Imlx_linux -O3 -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

GCC	=	${COMPILER} ${42FLAGS} ${LIBFLAGS}

#CLEAN

RM	=	rm -f

#COMPILE FOR DIFFERENT MACHINES

ifeq (${UNAME}, Darwin)
#mac
	GCC += ${MLXFLAGS}
else ifeq (${UNAME}, FreeBSD)
#FreeBSD
	CC = clang
else
#Linux and others...
	GCC += ${MLXFLAGS_LINUX}
endif

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# +*+*+**++*+*+*+*+*+*+**+ RULES ++*+**+**++*+*+*+*+*+*+*+*+*+

${NAME}:	${SRCS} | libft
	@${GCC} ${SRCS}  -o ${NAME}
	@echo "${COLOUR_GREEN} >>> SO_LONG OK <<< ${COLOUR_END}"

all:	${NAME} submodule

submodule:
	@git submodule update --init --recursive

libft:
	@make -C ${LIBFT_DIR}

clean:
	@${MAKE} clean -C ${LIBFT_DIR}
	@echo "${COLOUR_YELLOW} >>> OBJS CLEANED <<< ${COLOUR_END}"

fclean:		clean
	@${MAKE} fclean -C ${LIBFT_DIR}
	@${RM} ${NAME}
	@echo "${COLOUR_YELLOW} >>> ALL CLEANED <<< ${COLOUR_END}"

re:	fclean all

.PHONY:	all clean fclean re libft submodule
