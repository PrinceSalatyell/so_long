/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:46:30 by josanton          #+#    #+#             */
/*   Updated: 2023/03/06 23:06:03 by josanton         ###   ########.fr       */
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
# define PX 64

// DEFINE PATH VARIABLES

# define WINDOWS_NAME "so_long"
# define DOOR_CLOSED "./assets/door_closed.xpm"
# define DOOR_OPEN "./assets/door_open.xpm"
# define PLAYER_LEFT "./assets/player_left.xpm"
# define PLAYER_RIGHT "./assets/player_right.xpm"
# define PLAYER_UP "./assets/player_up.xpm"
# define PLAYER_DOWN "./assets/player_down.xpm"
# define COLLECTIBLES "./assets/collectible.xpm"
# define FLOOR "./assets/floor.xpm"
# define WALL "./assets/wall.xpm"

// USEFUL STRUCTS

enum e_events
{
	KEY_PRESS = 2,
	KeyPressMask = 1L << 0,
	DESTROY_NOTIFY = 17,
	ButtonPressMask = 1L << 2
};

typedef struct s_player
{
	void	*avatar;
	void	*avatar_up;
	void	*avatar_down;
	void	*avatar_left;
	void	*avatar_right;
	int		x;
	int		y;
	int		steps;
}			t_player;

typedef struct s_map
{
	char		**st;
	void		*wall;
	void		*door;
	void		*space;
	void		*coin;
	int			collectibles;
	int			collectibles_copy;
	int			width;
	int			height;
	int			exit_found;
	t_player	player;
}			t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_map	*map;
}			t_vars;

// FUNCTIONS

t_vars		*vars(void);

t_map		*map(void);

t_player	player(void);

bool		valid_syntax(char *file_name);

void		validate_path(void);

void		map_error(char *reason);

void		load_images(void);

void		move(int keycode, int x, int y);

void		print_map(int i, int j);

int			exit_game(void);

#endif
