/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:10:40 by josanton          #+#    #+#             */
/*   Updated: 2022/11/26 21:49:03 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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


int	exit_game(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hooks(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		mlx_destroy_window(vars->mlx, vars->win);
	if (keycode == LEFT)
		ft_printf("left");
	if (keycode == RIGHT)
		ft_printf("right");
	if (keycode == UP)
		ft_printf("up");
	if (keycode == DOWN)
		ft_printf("down");
	if (keycode == A)
		ft_printf("a");
	if (keycode == W)
		ft_printf("w");
	if (keycode == S)
		ft_printf("s");
	if (keycode == D)
		ft_printf("d");
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_img	image;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");
	mlx_key_hook(vars.win, key_hooks, &vars);
	image.relative_path = "./assets/protect.xpm";
	image.img = mlx_xpm_file_to_image(vars.mlx, image.relative_path,
			&image.width, &image.height);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 50, 50);
	mlx_loop(vars.mlx);
	return (0);
}
