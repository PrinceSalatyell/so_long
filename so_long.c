/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:10:40 by josanton          #+#    #+#             */
/*   Updated: 2023/03/05 03:13:11 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	render_next_frame()
// {
// 	ft_printf("We got here!\n");
// 	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->image->img, 50, 50);
// }

int	exit_game()
{
	int	i;

	i = 0;
	while (i < *(vars()->map->height))
		free(vars()->map->structure[i++]);
	free(vars()->map->structure);
	mlx_destroy_window(vars()->mlx, vars()->win);
	mlx_destroy_image(vars()->mlx, vars()->map->wall);
	mlx_destroy_image(vars()->mlx, vars()->map->space);
	mlx_destroy_image(vars()->mlx, vars()->map->door);
	mlx_destroy_image(vars()->mlx, vars()->map->coin);
	mlx_destroy_image(vars()->mlx, vars()->map->player->avatar);
	mlx_destroy_display(vars()->mlx);
	free(vars()->mlx);
	ft_printf("EXIT!\n");
	//ft_putstr_fd(message, 1);
	//ft_putstr_fd("\n", 1);
	//free_so_long();
	exit(0);
}

int	key_hooks(int keycode)
{
	if (keycode == ESC)
 		exit_game();
// 	if (keycode == LEFT)
// 		ft_printf("left");
// 	if (keycode == RIGHT)
// 		mlx_loop_hook(vars()->mlx, render_next_frame, &vars())
// 	if (keycode == UP)
// 		ft_printf("up");
// 	if (keycode == DOWN)
// 		ft_printf("down");
// 	if (keycode == A)
// 		ft_printf("a");
// 	if (keycode == W)
// 		ft_printf("w");
// 	if (keycode == S)
// 		ft_printf("s");
// 	if (keycode == D)
// 		ft_printf("d");
	return (0);
}

// int	force_exit(void)
// {

// }

int	main(int argc, char **argv)
{
	t_img	image;
	int		fd;

	if (argc != 2)
		map_error("Make sure to to provide a map: ./so_long <map_name>.ber");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		map_error("Error opening the map file. Are you sure the name is correct?");
	vars()->map = map();
	valid_syntax(argv[1]);
	validate_path(fd, 0);
	close(fd);
	vars()->mlx = mlx_init();
	if (vars()->mlx)
		vars()->win = mlx_new_window(vars()->mlx, PIXELS * *(vars()->map->width),
			PIXELS * *(vars()->map->height), "so_long");
	vars()->map->player = player();
	mlx_hook(vars()->win, KEY_PRESS, KeyPressMask, key_hooks, NULL);
	mlx_hook(vars()->win, DESTROY_NOTIFY, ButtonPressMask,
		exit_game, NULL);
	load_images();
	//mlx_key_hook(vars()->win, key_hooks, &vars()->;
	//mlx_loop_hook(vars()->mlx, render_next_frame, &vars()->;
	mlx_loop(vars()->mlx);

	

	
	
	
	free(vars()->map->width);
	free(vars()->map->collectibles);
	free(vars()->map->collectibles_copy);
	free(vars()->map->height);
	free(vars()->map->exit_found);
	return (0);
}
