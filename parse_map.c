/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josanton <josanton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:13:59 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/06 23:01:49 by josanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_nl(const char *str)
{
	unsigned int	l;

	l = 0;
	while (*str && *str != 10)
	{
		l++;
		str++;
	}
	return (l);
}

void	read_map(int fd, int i)
{
	char	*str;

	str = get_next_line(fd);
	if (str)
		read_map(fd, i + 1);
	else
	{
		if (i == 0)
			map_error("empty map");
		vars()->map->height = i;
		vars()->map->st = malloc(sizeof(char *) * (i + 1));
		if (!vars()->map->st)
			map_error("Malloc error");
	}
	vars()->map->st[i] = str;
}

void	valid_shape(int i, int j)
{
	(vars()->map->width) = (int) ft_strlen_nl(vars()->map->st[0]);
	while (i < vars()->map->height)
	{
		if (ft_strlen_nl(vars()->map->st[i]) != (vars()->map->width))
			map_error("The map is not rectangular");
		if (vars()->map->st[i][0] != '1' || \
		vars()->map->st[i][vars()->map->width - 1] != '1')
			map_error("Border should be a wall");
		i++;
	}
	while (j < vars()->map->width)
	{
		if (vars()->map->st[0][j] != '1' || \
		vars()->map->st[vars()->map->height - 1][j] != '1')
			map_error("Border should be a wall");
		j++;
	}
}

void	valid_elements(int i, int j, int p_count, int e_count)
{
	while (++i < vars()->map->height)
	{
		j = -1;
		while (++j < vars()->map->width)
		{
			if (vars()->map->st[i][j] == 'P')
			{	
				p_count++;
				vars()->map->player.x = j;
				vars()->map->player.y = i;
			}
			else if (vars()->map->st[i][j] == 'E')
				e_count++;
			else if (vars()->map->st[i][j] == 'C')
				vars()->map->collectibles++;
			else if (vars()->map->st[i][j] != '0' && vars()->map->st[i][j] \
			!= '1' && vars()->map->st[i][j] != '\n')
				map_error("Valid elements are: 1, 0, C, P & E");
		}
	}
	if (vars()->map->collectibles < 1 || e_count != 1 || p_count != 1)
		map_error("You need at least one 'C' and exactly one 'P' and one 'E'");
}

bool	valid_syntax(char *file_name)
{
	int		len;
	int		fd;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strcmp(file_name + len - 4, ".ber") != 0)
		map_error("Wrong file extension. Should be <.ber>");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		map_error("Error opening the file");
	read_map(fd, 0);
	valid_shape(0, 0);
	valid_elements(-1, -1, 0, 0);
	close(fd);
	return (true);
}
