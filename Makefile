# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:36:16 by josanton          #+#    #+#              #
#    Updated: 2022/08/05 12:53:26 by salatiel         ###   ########.fr        #
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

LIB_INC =	-L${LIBFT_DIR} -lft

MLX_INC =	-I

# LIBFLAGS =	

MLXFLAGS =	-L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

MLXFLAGS_LINUX	=	-L ${MLX_LINUX_DIR} -lmlx -lXext -lX11 -lm -lz

GCC	=	${CC} ${42FLAGS}

#CLEAN

RM	=	rm -f

#COMPILE FOR DIFFERENT MACHINES

ifeq (${UNAME}, Darwin)
#mac
	GCC+=${MLXFLAGS}
else ifeq (${UNAME}, FreeBSD)
#FreeBSD
	CC = clang
else
#Linux and others...
	GCC+=${MLXFLAGS_LINUX}
endif

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# +*+*+**++*+*+*+*+*+*+**+ RULES ++*+**+**++*+*+*+*+*+*+*+*+*+

all:	${NAME} submodule

${NAME}:	${OBJS} | libft
	@echo ${GCC}
	@echo ${OBJS}
	@echo ${MLX_INC}
	@${GCC} ${OBJS} -o ${NAME}
	@echo "${COLOUR_GREEN} >>> SO_LONG OK <<< ${COLOUR_END}"

submodule:
	@git submodule update --init --recursive

%.o: %.c
	@${CC} ${42FLAGS} -I mlx_linux -c $< -o $@

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
