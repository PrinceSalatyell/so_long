# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: easybreezy <easybreezy@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:36:16 by josanton          #+#    #+#              #
#    Updated: 2022/06/28 19:19:26 by easybreezy       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================== ONLY COMPILES ON MACS ====================================

# COMPILATION VARS

SRCS	=	so_long.c

NAME	=	so_long

#DIRECTORIES

LIBFT_DIR	=	libft/

MLX_DIR	=	mlx/

#GCC & FLAGS

COMPILER	=	gcc

42FLAGS	=	-Wall -Wextra -Wextra -Imlx

LIBFLAGS =	-L${LIBFT_DIR} -lft

MLXFLAGS =	-L${MLX_DIR} -lmlx -framework OpenGL -framework AppKit

GCC	=	${COMPILER} ${42FLAGS} ${LIBFLAGS} ${MLXFLAGS}

#CLEAN

RM	=	rm -f

#COLORS

COLOUR_GREEN=\033[7;1;32m
COLOUR_END=\033[0m
COLOUR_YELLOW=\033[7;1;33m

# +*+*+**++*+*+*+*+*+*+**+ RULES ++*+**+**++*+*+*+*+*+*+*+*+*+

${NAME}:	${SRCS} | libft
	@${GCC} ${SRCS}  -o ${NAME}
	@echo "$(COLOUR_GREEN) >>> SO_LONG OK <<< $(COLOUR_END)"

all:	${NAME} submodule

submodule:
	@git submodule update --init --recursive

libft:
	@make -C ${LIBFT_DIR}

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(COLOUR_YELLOW) >>> OBJS CLEANED <<< $(COLOUR_END)"

fclean:		clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@${RM} ${NAME}
	@echo "$(COLOUR_YELLOW) >>> ALL CLEANED <<< $(COLOUR_END)"

re:	fclean all

.PHONY:	all clean fclean re libft submodule
