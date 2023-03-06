/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:26:48 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/06 19:43:52 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void)
{
	int	width;
	int	height;

	width = PX;
	height = PX;
	(vars())->map->space = mlx_xpm_file_to_image(vars()->mlx, \
	FLOOR, &width, &height);
	(vars())->map->wall = mlx_xpm_file_to_image(vars()->mlx, \
	WALL, &width, &height);
	(vars())->map->door = mlx_xpm_file_to_image(vars()->mlx, \
	DOOR_CLOSED, &width, &height);
	(vars())->map->coin = mlx_xpm_file_to_image(vars()->mlx, \
	COLLECTIBLES, &width, &height);
	(vars())->map->player.avatar_down = mlx_xpm_file_to_image(vars()->mlx, \
	PLAYER_DOWN, &width, &height);
	(vars())->map->player.avatar_up = mlx_xpm_file_to_image(vars()->mlx, \
	PLAYER_UP, &width, &height);
	(vars())->map->player.avatar_left = mlx_xpm_file_to_image(vars()->mlx, \
	PLAYER_LEFT, &width, &height);
	(vars())->map->player.avatar_right = mlx_xpm_file_to_image(vars()->mlx, \
	PLAYER_RIGHT, &width, &height);
	(vars())->map->player.avatar = vars()->map->player.avatar_down;
	print_map(-1, -1);
}

void	print_map(int i, int j)
{
	while (++i < (vars()->map->height))
	{
		j = -1;
		while (++j < (vars()->map->width))
		{
			if (vars()->map->st[i][j] == '1')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->wall, PX * j, PX * i);
			else if (vars()->map->st[i][j] == '0')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->space, PX * j, PX * i);
			else if (vars()->map->st[i][j] == 'C')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->coin, PX * j, PX * i);
			else if (vars()->map->st[i][j] == 'E')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->door, PX * j, PX * i);
			else if (vars()->map->st[i][j] == 'P')
				mlx_put_image_to_window(vars()->mlx, \
				vars()->win, vars()->map->player.avatar, \
				PX * vars()->map->player.x, PX * vars()->map->player.y);
		}
	}
}

void	collide(int y_x, int plus_minus, int x, int y)
{
	if (vars()->map->st[y][x] == 'C')
	{
		((vars()->map->collectibles))--;
		vars()->map->st[y][x] = '0';
	}
	if (vars()->map->st[y][x] == 'E' && !((vars()->map->collectibles)))
		exit_game();
	if (vars()->map->st[y][x] == 'E')
	{
		if (y_x == 0 && plus_minus == 0)
			(vars()->map->player.y)++;
		else if (y_x == 0 && plus_minus == 1)
			(vars()->map->player.y)--;
		else if (y_x == 1 && plus_minus == 0)
			(vars()->map->player.x)++;
		else if (y_x == 1 && plus_minus == 1)
			(vars()->map->player.x)--;
		vars()->map->st[vars()->map->player.y][vars()->map->player.x] = 'P';
	}
	else
		ft_printf("Steps -> %i\n", ++vars()->map->player.steps);
}

void	animation(int key, int x, int y)
{
	if (key == W || key == UP)
	{
		vars()->map->player.avatar = vars()->map->player.avatar_up;
		collide(0, 0, vars()->map->player.x, vars()->map->player.y);
	}
	if (key == S || key == DOWN)
	{
		vars()->map->player.avatar = vars()->map->player.avatar_down;
		collide(0, 1, vars()->map->player.x, vars()->map->player.y);
	}
	if (key == A || key == LEFT)
	{
		vars()->map->player.avatar = vars()->map->player.avatar_left;
		collide(1, 0, vars()->map->player.x, vars()->map->player.y);
	}
	if (key == D || key == RIGHT)
	{
		vars()->map->player.avatar = vars()->map->player.avatar_right;
		collide(1, 1, vars()->map->player.x, vars()->map->player.y);
	}
	if (vars()->map->st[y][x] != 'E')
		vars()->map->st[y][x] = 'P';
}

void	move(int key, int x, int y)
{
	if ((key == A || key == LEFT) && vars()->map->st[y][x - 1] != '1')
	{
		vars()->map->st[y][x] = '0';
		(vars()->map->player.x)--;
		animation(key, x - 1, y);
	}
	else if ((key == D || key == RIGHT) && vars()->map->st[y][x + 1] != '1')
	{
		vars()->map->st[y][x] = '0';
		(vars()->map->player.x)++;
		animation(key, x + 1, y);
	}
	else if ((key == W || key == UP) && vars()->map->st[y - 1][x] != '1')
	{
		vars()->map->st[y][x] = '0';
		(vars()->map->player.y)--;
		animation(key, x, y - 1);
	}
	else if ((key == S || key == DOWN) && vars()->map->st[y + 1][x] != '1')
	{
		vars()->map->st[y][x] = '0';
		(vars()->map->player.y)++;
		animation(key, x, y + 1);
	}
}
