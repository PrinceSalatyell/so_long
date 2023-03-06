/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:26:48 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/06 02:11:10 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void)
{
	int	width;
	int height;

	width = PIXELS;
	height = PIXELS;
	vars()->map->space = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/floor.xpm", &width, &height);
	vars()->map->wall = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/wall.xpm", &width, &height);
	vars()->map->door = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/door_closed.xpm", &width, &height);
	vars()->map->coin = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/collectible.xpm",
			&width, &height);
	vars()->map->player->avatar_down = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/player_down.xpm", &width, &height);
	vars()->map->player->avatar_up = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/player_up.xpm", &width, &height);
	vars()->map->player->avatar_left = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/player_left.xpm", &width, &height);
	vars()->map->player->avatar_right = mlx_xpm_file_to_image(vars()->mlx,
		"./assets/player_right.xpm", &width, &height);
	vars()->map->player->avatar = vars()->map->player->avatar_down;
	print_map(-1, -1);
}

void	print_map(int i, int j)
{
	while (++i < *(vars()->map->height))
	{
		j = -1;
		while (++j < *(vars()->map->width))
		{
			if (vars()->map->structure[i][j] == '1')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->wall, PIXELS * j, PIXELS * i);
			else if (vars()->map->structure[i][j] == '0')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->space, PIXELS * j, PIXELS * i);
			else if (vars()->map->structure[i][j] == 'C')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->coin, PIXELS * j, PIXELS * i);
			else if (vars()->map->structure[i][j] == 'E')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->door, PIXELS * j, PIXELS * i);
			else if (vars()->map->structure[i][j] == 'P')
				mlx_put_image_to_window(vars()->mlx,
					vars()->win, vars()->map->player->avatar,
					PIXELS * vars()->map->player->x, PIXELS * vars()->map->player->y);
		}
	}
}

void	collide(int y_x, int plus_minus)
{
	int	x;
	int	y;

	x = vars()->map->player->x;
	y = vars()->map->player->y;
	if (vars()->map->structure[y][x] == 'C')
	{
		(*(vars()->map->collectibles))--;
		vars()->map->structure[y][x] = '0';
	}
	if (vars()->map->structure[y][x] == 'E' && !(*(vars()->map->collectibles)))
		exit_game();
	if (vars()->map->structure[y][x] == 'E')
	{
		if (y_x == 0 && plus_minus == 0)
			(vars()->map->player->y)++;
		else if (y_x == 0 && plus_minus == 1)
			(vars()->map->player->y)--;
		else if (y_x == 1 && plus_minus == 0)
			(vars()->map->player->x)++;
		else if (y_x == 1 && plus_minus == 1)
			(vars()->map->player->x)--;
		vars()->map->structure[vars()->map->player->y][vars()->map->player->x] = 'P';
	}
}

void	animation(int keycode, int x, int y)
{
	if (keycode == W || keycode == UP)
	{
		vars()->map->player->avatar = vars()->map->player->avatar_up;
		collide(0, 0);
	}
	if (keycode == S || keycode == DOWN)
	{
		vars()->map->player->avatar = vars()->map->player->avatar_down;
		collide(0, 1);
	}
	if (keycode == A || keycode == LEFT)
	{
		vars()->map->player->avatar = vars()->map->player->avatar_left;
		collide(1, 0);
	}
	if (keycode == D || keycode == RIGHT)
	{
		vars()->map->player->avatar = vars()->map->player->avatar_right;
		collide(1, 1);
	}
	if (vars()->map->structure[y][x] != 'E')
		vars()->map->structure[y][x] = 'P';
}

void	move(int keycode, int x, int y)
{
	if ((keycode == A || keycode == LEFT) && vars()->map->structure[y][x - 1] != '1')
	{
		vars()->map->structure[y][x] = '0';
		(vars()->map->player->x)--;
		animation(keycode, x - 1, y);
	}
	else if ((keycode == D || keycode == RIGHT) && vars()->map->structure[y][x + 1] != '1')
	{
		vars()->map->structure[y][x] = '0';
		(vars()->map->player->x)++;
		animation(keycode, x + 1, y);
	}
	else if ((keycode == W || keycode == UP) && vars()->map->structure[y - 1][x] != '1')
	{
		vars()->map->structure[y][x] = '0';
		(vars()->map->player->y)--;
		animation(keycode, x, y - 1);
	}
	else if ((keycode == S || keycode == DOWN) && vars()->map->structure[y + 1][x] != '1')
	{
		vars()->map->structure[y][x] = '0';
		(vars()->map->player->y)++;
		animation(keycode, x, y + 1);
	}
}
