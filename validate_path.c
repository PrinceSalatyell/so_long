/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:50:38 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/02 02:13:43 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

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
		while (col < *(vars()->map->size))
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

void	find_collectibles(int **map, t_point *collectibles)
{
	int		n_collectibles;
	int		row;
	int		col;

	n_collectibles = 0;
	row = 0;
	while (row < *(vars()->map->size))
	{
		col = 0;
		while (col < *(vars()->map->size))
		{
			if (map[row][col] == 'C')
			{
				collectibles[n_collectibles].x = col;
				collectibles[n_collectibles].y = row;
				n_collectibles++;
			}
			col++;
		}
		row++;
	}
}

int	is_valid_move(int **map, int x, int y, int *n_collectibles)
{
	if (x < 0 || x >= *(vars()->map->size) || y < 0
		|| y >= *(vars()->map->size))
		return (0);
	if (map[y][x] == 'E' && *n_collectibles == 0)
		return (1);
	if (map[y][x] == 'C')
		(*n_collectibles)--;
	return (map[y][x] != '1');
}

int	is_valid_path(int **map, int n_collectibles,
	t_point current, t_point destination)
{
	if (current.x == destination.x && current.y == destination.y)
		return (n_collectibles == 0);
	if (!is_valid_move(map, current.x, current.y, &n_collectibles))
		return (0);
	map[current.y][current.x] = '1';
	if (is_valid_path(map, n_collectibles,
			(t_point){current.x - 1, current.y}, destination))
		return (1);
	if (is_valid_path(map, n_collectibles,
			(t_point){current.x + 1, current.y}, destination))
		return (1);
	if (is_valid_path(map, n_collectibles,
			(t_point){current.x, current.y - 1}, destination))
		return (1);
	if (is_valid_path(map, n_collectibles,
			(t_point){current.x, current.y + 1}, destination))
		return (1);
	map[current.y][current.x] = '0';
	return (0);
}

int	validate_path(int fd, int i)
{
	int		**map;
	t_point	*collectibles;
	t_point	current;
	t_point	destination;

	map = (int **)malloc(*(vars()->map->size) * sizeof(int *));
	collectibles = malloc(sizeof(t_point) * *(vars()->map->size)
			* *(vars()->map->size));
	while (i < *(vars()->map->size))
		map[i++] = (int *)malloc(*(vars()->map->size) * sizeof(int));
	read_map(fd, map);
	find_collectibles(map, collectibles);
	current = collectibles[0];
	destination = collectibles[*(vars()->map->collectibles) - 1];

	if (is_valid_path(map, *(vars()->map->collectibles), current, destination))
		write(1, "There is a valid path\n", 22);
	else
		write(1, "There is no valid path\n", 23);
	i = 0;
	while (i < *(vars()->map->size))
		free(map[i++]);
	free(map);

	return (0);
}
