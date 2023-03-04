/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:46:30 by josanton          #+#    #+#             */
/*   Updated: 2023/03/04 18:41:20 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// LIBRARIES

# include "libft/libft.h"
# include <mlx.h>
# include <stdbool.h>

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

enum e_events
{
	KEY_PRESS = 2,
	KeyPressMask = 1L << 0,
	DESTROY_NOTIFY = 17,
	ButtonPressMask = 1L << 2
};

typedef struct s_img {
	void	*img;
	char	*relative_path;
	int		height;
	int		width;
}			t_img;

typedef struct s_player
{
	t_img	*avatar;
	int		x;
	int		y;
}			t_player;

typedef struct s_map
{
	t_img	*wall;
	t_img	*door;
	int		*collectibles;
	int		*collectibles_copy;
	int		*width;
	int		*height;
	int		*exit_found;
}			t_map;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
}			t_vars;


// FUNCTIONS

t_vars	*vars(void);

t_map	*map(void);

bool	valid_syntax(char *file_name);

int		validate_path(int fd, int i);

void	map_error(char *reason);

#endif
