/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:46:30 by josanton          #+#    #+#             */
/*   Updated: 2022/11/26 22:07:41 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIBRARIES

# include "libft/libft.h"
# include <mlx.h>

// DEFINE KEYS

# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define A 97
# define D 100
# define W 119
# define S 115

// USEFUL STRUCTS

typedef struct s_vars {
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_img {
	void	*img;
	char	*relative_path;
	int		height;
	int		width;
}			t_img;


// FUNCTIONS

#endif
