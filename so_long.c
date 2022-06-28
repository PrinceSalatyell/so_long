/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: easybreezy <easybreezy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:34:14 by josanton          #+#    #+#             */
/*   Updated: 2022/06/28 21:57:03 by easybreezy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_win	new_program(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win){mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), w, h});
}


int	main(void)
{
	t_win	tutorial;
	t_img	image;

	tutorial = new_program(300, 300, "tutorial");
	if (!tutorial.mlx_ptr)
		return (1);
	image.win = tutorial;
	image.img_ptr = mlx_new_image(tutorial.mlx_ptr, 4, 4);
	image.addr = mlx_get_data_addr(image.img_ptr, &image.bpp,
			&image.line_len, &image.endian);
	image.w = 4;
	image.h = 4;
	printf("Let's Find out what's inside our structure :D\n");
	printf("img_ptr		: [%p]\n", image.img_ptr);
	printf("bpp		: [%d]\n", image.bpp);
	printf("line_len	: [%d]\n", image.line_len);
	printf("endian		: [%d]\n", image.endian);
	printf("addr		: [%p]\n", image.addr);
	mlx_loop(tutorial.mlx_ptr);
	return (0);
}
