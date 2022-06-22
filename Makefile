# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josanton <josanton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 13:36:16 by josanton          #+#    #+#              #
#    Updated: 2022/06/22 15:24:28 by josanton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	so_long.c

LIBFT_DIR = libft/

NAME	=	so_long

GCC		=	gcc -Wall -Wextra -Wextra -L $(LIBFT_DIR) -lft

RM		=	rm -f


${NAME}:	${SRCS}
			@${MAKE} -C $(LIBFT_DIR)
			@${GCC} ${SRCS}  -o ${NAME}

all:		${NAME}

clean:		
			$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re