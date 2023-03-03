/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:10:40 by josanton          #+#    #+#             */
/*   Updated: 2023/03/03 21:32:19 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	render_next_frame()
// {
// 	ft_printf("We got here!\n");
// 	mlx_put_image_to_window(vars()->mlx, vars()->win, vars()->image->img, 50, 50);
// }

// int	exit_game(int keycode)
// {
// 	mlx_destroy_window(vars()->mlx, vars()->win);
// 	mlx_destroy_image(vars()->mlx, vars()->image->img);
// 	mlx_destroy_display(vars()->mlx);
// 	ft_printf("EXIT!\n");
// 	//ft_putstr_fd(message, 1);
// 	//ft_putstr_fd("\n", 1);
// 	//free_so_long();
// 	exit(0);
// }

// int	key_hooks(int keycode)
// {
// 	if (keycode == ESC)
// 		exit_game(keycode);
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
// 	return (0);
// }

// int	force_exit(void)
// {

// }

int	main(int argc, char **argv)
{
	//t_img	image;

	//vars()->mlx = mlx_init();
	//vars()->win = mlx_new_window(vars()->mlx, 640, 480, "Hello World!");
	//mlx_key_hook(vars()->win, key_hooks, &vars()->;
	//image.relative_path = "./assets/protect.xpm";
	//image.img = mlx_xpm_file_to_image(vars()->mlx, image.relative_path,
	//		&image.width, &image.height);
	vars()->map = map();
	//mlx_hook(vars()->win, KEY_PRESS, KeyPressMask, key_hooks, NULL);
	//mlx_hook(vars()->win, DESTROY_NOTIFY, ButtonPressMask,
	//	exit_game, NULL);
	//mlx_loop_hook(vars()->mlx, render_next_frame, &vars()->;
	//mlx_loop(vars()->mlx);

	int		fd;
	int		ret;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	valid_syntax(argv[1]);
	ret = validate_path(fd, 0);
	close(fd);
	free(vars()->map->width);
	free(vars()->map->collectibles);
	free(vars()->map->height);
	return (ret);
}
