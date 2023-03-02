/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:07:20 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/02 01:42:55 by salatiel         ###   ########.fr       */
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
	map.size = malloc(sizeof(int) * 1);
	*(map.collectibles) = 0;

	return (&map);
}
