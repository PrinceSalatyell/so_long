/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:50:38 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/06 22:53:50 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_move(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'P')
		return (0);
	if (map[y][x] == 'C')
		vars()->map->collectibles_copy--;
	if (map[y][x] == 'E')
		vars()->map->exit_found++;
	map[y][x] = '1';
	return (1);
}

int	is_valid_path(char **map, int x, int y)
{
	int	valid;

	valid = 0;
	if (!(vars()->map->collectibles_copy) && vars()->map->exit_found)
		return (1);
	if (is_valid_move(map, x + 1, y))
		valid = is_valid_path(map, x + 1, y);
	if (is_valid_move(map, x - 1, y))
		valid = is_valid_path(map, x - 1, y);
	if (is_valid_move(map, x, y + 1))
		valid = is_valid_path(map, x, y + 1);
	if (is_valid_move(map, x, y - 1))
		valid = is_valid_path(map, x, y - 1);
	return (valid);
}

void	validate_path(void)
{
	char	**map;
	int		i;
	int		valid;

	map = malloc(sizeof(char *) * (vars()->map->height + 1));
	i = -1;
	while (++i < (vars()->map->height))
		map[i] = ft_strdup(vars()->map->st[i]);
	map[i] = NULL;
	vars()->map->collectibles_copy = vars()->map->collectibles;
	valid = !is_valid_path(map, vars()->map->player.x, vars()->map->player.y);
	i = 0;
	while (i < (vars()->map->height))
		free(map[i++]);
	free(map);
	if (valid)
		map_error("There is no valid path");
}
