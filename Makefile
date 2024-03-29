# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josanton <josanton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:36:16 by josanton          #+#    #+#              #
#    Updated: 2023/03/06 18:54:50 by josanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION VARS

SRCS	=	so_long.c		\
			parse_map.c		\
			utils.c			\
			validate_path.c	\
			image_management.c

OBJS	=	${SRCS:%.c=${DIR_OBJ}%.o}

NAME	=	so_long

#DIRECTORIES

LIBFT_DIR	=	libft/

MLX_LINUX_DIR	=	mlx_linux/

DIR_OBJ = objs/

#GCC & FLAGS

CC	=	gcc

42FLAGS	=	-Wall -Werror -Wextra -g #-fsanitize=leak

GCC	=	${CC} ${42FLAGS}

#CLEAN

RM	=	rm -f

MLX=-Ilibft/ -Imlx_linux/ -L${LIBFT_DIR} -lft -L${MLX_LINUX_DIR} -lmlx -L/usr/lib/ -lXext -lX11 -lm -lz

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# ================================ R U L E S ================================

all:	${NAME}

${NAME}:	${OBJS} mlx_linux/libmlx.a libft/libft.a
	@${GCC} -o ${NAME} ${OBJS} ${MLX}
	@echo "${COLOUR_GREEN} >>> SO_LONG OK <<< ${COLOUR_END}"

${DIR_OBJ}%.o:%.c
	@git submodule update --init --recursive
	@mkdir -p ${dir $@}
	@${CC} ${42FLAGS} -I mlx_linux -c $< -o $@

libft/libft.a:
	@make -s -C ${LIBFT_DIR}

mlx_linux/libmlx.a:
	@make -s -C ${MLX_LINUX_DIR}
	@echo "${COLOUR_GREEN} >>> MLX OK <<< ${COLOUR_END}"

clean:
	@${MAKE} -s clean -C ${LIBFT_DIR}
	@${MAKE} -s clean -C ${MLX_LINUX_DIR}
	@${RM} -r ${DIR_OBJ}
	@echo "${COLOUR_YELLOW} >>> OBJS CLEANED <<< ${COLOUR_END}"

fclean:		clean
	@${MAKE} -s fclean -C ${LIBFT_DIR}
	@${RM} ${NAME}
	@echo "${COLOUR_YELLOW} >>> ALL CLEANED <<< ${COLOUR_END}"

re:	fclean all

.PHONY:	all clean fclean re libft submodule mlx
