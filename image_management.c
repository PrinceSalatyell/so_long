/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:26:48 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/05 03:13:13 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void)
{
	int	width;
	int height;

	width = PIXELS;
	height = PIXELS;
	vars()->map->space = mlx_xpm_file_to_image(vars()->mlx, "./assets/floor.xpm",
			&width, &height);
	vars()->map->wall = mlx_xpm_file_to_image(vars()->mlx, "./assets/wall.xpm",
			&width, &height);
	vars()->map->door = mlx_xpm_file_to_image(vars()->mlx, "./assets/door_closed.xpm",
			&width, &height);
	vars()->map->coin = mlx_xpm_file_to_image(vars()->mlx, "./assets/collectible.xpm",
			&width, &height);
	vars()->map->player->avatar = mlx_xpm_file_to_image(vars()->mlx, "./assets/player_down.xpm",
			&width, &height);
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
					vars()->win, vars()->map->player->avatar, PIXELS * j, PIXELS * i);
		}
	}
}

// void	move(int x, int y)
// {
// 	if (x < 0 || x >= *(vars()->map->width) || y < 0
// 		|| y >= *(vars()->map->height) || map[y][x] == 1)
// 		return (0);
// 	if (map[y][x] == 'C')
// 	{
// 		(*(vars()->map->collectibles))--;
// 		vars()->map->structure[y][x] = '0';
// 	}
// 	if (map[y][x] == 'E' && !(*(vars()->map->collectibles)))
// 		exit(0);
	
// 	print_map(-1, -1);
// }