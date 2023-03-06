/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:10:40 by josanton          #+#    #+#             */
/*   Updated: 2023/03/06 23:09:05 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(void)
{
	print_map(-1, -1);
	return (1);
}

int	exit_game(void)
{
	int	i;

	i = 0;
	while (i < (vars()->map->height))
		free(vars()->map->st[i++]);
	free(vars()->map->st);
	mlx_destroy_window(vars()->mlx, vars()->win);
	mlx_destroy_image(vars()->mlx, vars()->map->wall);
	mlx_destroy_image(vars()->mlx, vars()->map->space);
	mlx_destroy_image(vars()->mlx, vars()->map->door);
	mlx_destroy_image(vars()->mlx, vars()->map->coin);
	mlx_destroy_image(vars()->mlx, vars()->map->player.avatar_down);
	mlx_destroy_image(vars()->mlx, vars()->map->player.avatar_left);
	mlx_destroy_image(vars()->mlx, vars()->map->player.avatar_right);
	mlx_destroy_image(vars()->mlx, vars()->map->player.avatar_up);
	mlx_destroy_display(vars()->mlx);
	free(vars()->mlx);
	ft_printf("EXIT!\n");
	exit(0);
}

int	key_hooks(int keycode)
{
	int	size;

	size = PX;
	if (keycode == ESC)
		exit_game();
	else
	{
		move(keycode, vars()->map->player.x, vars()->map->player.y);
		if (!((vars()->map->collectibles)))
		{
			mlx_destroy_image(vars()->mlx, vars()->map->door);
			(vars())->map->door = mlx_xpm_file_to_image(vars()->mlx, \
			DOOR_OPEN, &size, &size);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	vars()->map = map();
	if (argc != 2)
		map_error("Make sure to to provide a map: ./so_long <map_name>.ber");
	vars()->map->player = player();
	valid_syntax(argv[1]);
	validate_path();
	vars()->mlx = mlx_init();
	if (vars()->mlx)
		(vars())->win = mlx_new_window(vars()->mlx, PX * (vars()->map->width), \
		PX * (vars()->map->height), "so_long");
	mlx_hook(vars()->win, KEY_PRESS, KeyPressMask, key_hooks, NULL);
	mlx_hook(vars()->win, DESTROY_NOTIFY, ButtonPressMask,
		exit_game, NULL);
	load_images();
	mlx_loop_hook(vars()->mlx, render_next_frame, NULL);
	mlx_loop(vars()->mlx);
	return (0);
}
