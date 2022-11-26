/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:10:40 by josanton          #+#    #+#             */
/*   Updated: 2022/11/26 18:39:12 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}			t_vars;


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

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello World!");
	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_hook(vars.win, 2, 1L<<0, exit_game, &vars);
	mlx_key_hook(vars.win, key_hooks, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
