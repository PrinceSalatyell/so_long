/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:50:38 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/04 19:28:38 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, int **map)
{
	char	*line;
	int		row;
	int		col;

	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		col = 0;
		while (col < *(vars()->map->width))
		{
			if (line[col] == '0' || line[col] == '1')
				map[row][col] = line[col] - '0';
			else
				map[row][col] = line[col];
			col++;
		}
		free(line);
		row++;
		line = get_next_line(fd);
	}
	free(line);
}

int	is_valid_move(int **map, int x, int y)
{
	if (x < 0 || x >= *(vars()->map->width) || y < 0
		|| y >= *(vars()->map->height) || map[y][x] == 1)
		return (0);
	if (map[y][x] == 'C')
		(*(vars()->map->collectibles_copy))--;
	if (map[y][x] == 'E')
		*(vars()->map->exit_found) = 1;
	map[y][x] = 1;
	return (1);
}

int	is_valid_path(int **map, int x, int y)
{
	int	valid;

	valid = 0;
	if (!(*(vars()->map->collectibles_copy)) && *(vars()->map->exit_found))
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

void	validate_path(int fd, int i)
{
	int		**map;

	map = (int **)malloc(*(vars()->map->height) * sizeof(int *));
	while (i < *(vars()->map->height))
		map[i++] = (int *)malloc(*(vars()->map->width) * sizeof(int));
	read_map(fd, map);
	*(vars()->map->collectibles_copy) = *(vars()->map->collectibles);
	if (!is_valid_path(map, 2, 1))
		map_error("There is no valid path");
	i = 0;
	while (i < *(vars()->map->height))
		free(map[i++]);
	free(map);
}
