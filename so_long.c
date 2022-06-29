/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: easybreezy <easybreezy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:34:14 by josanton          #+#    #+#             */
/*   Updated: 2022/06/29 20:27:53 by easybreezy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}

void	img_info(t_img image)
{
	ft_printf("Let's Find out what's inside our structure :D\n");
	ft_printf("img_ptr		: [%p]\n", image.img_ptr);
	ft_printf("bpp		: [%d]\n", image.bpp);
	ft_printf("line_len	: [%d]\n", image.line_len);
	ft_printf("endian		: [%d]\n", image.endian);
	ft_printf("addr		: [%p]\n", image.addr);
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.line_len, &image.endian);
	image.w = w;
	image.h = h;
	img_info(image);
	return (image);
}

int	main(void)
{
	t_win	tutorial;
	t_img	image;

	tutorial = new_program(300, 300, "tutorial");
	if (!tutorial.mlx_ptr)
		return (1);
	image = new_img(4, 4, tutorial);
	ft_memcpy(image.addr,
		"s4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vfs4vf",
		16 * 4);
	mlx_put_image_to_window(image.win.mlx_ptr,
		image.win.win_ptr, image.img_ptr, 10, 10);
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}
