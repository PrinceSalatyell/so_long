/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:07:20 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/06 22:58:23 by josanton         ###   ########.fr       */
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

	return (&map);
}

t_player	player(void)
{
	static t_player	player;

	player.steps = 0;
	return (player);
}

void	map_error(char *reason)
{
	int	i;

	ft_printf("Error\n");
	ft_printf("The map provided is invalid\n");
	ft_printf("%s\n", reason);
	i = 0;
	if (vars()->map->st != NULL)
	{
		while (i < (vars()->map->height))
			free(vars()->map->st[i++]);
		free(vars()->map->st);
	}
	exit(0);
}
