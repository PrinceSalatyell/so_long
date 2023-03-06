/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:07:20 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/06 15:50:55 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vars	*vars(void)
{
	static t_vars	vars;

	return (&vars);
}

t_map	*map(void)
{
	static t_map	map;

	map.collectibles = malloc(sizeof(int) * 1);
	map.collectibles_copy = malloc(sizeof(int) * 1);
	map.width = malloc(sizeof(int) * 1);
	map.height = malloc(sizeof(int) * 1);
	map.exit_found = malloc(sizeof(int) * 1);
	*(map.collectibles) = 0;
	*(map.collectibles_copy) = 0;
	*(map.height) = 0;
	*(map.exit_found) = 0;
	return (&map);
}

t_player	*player(void)
{
	static t_player	player;

	player.steps = 0;
	return (&player);
}
