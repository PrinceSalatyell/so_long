/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salatiel <salatiel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 09:13:59 by salatiel          #+#    #+#             */
/*   Updated: 2023/03/02 02:04:06 by salatiel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(char *reason)
{
	ft_printf("Error\n");
	ft_printf("The map provided is invalid\n");
	ft_printf("%s\n", reason);
	exit(1);
}

char	*valid_shape(int fd, int i, int flag)
{
	char	*str;
	char	*prev_str;

	str = get_next_line(fd);
	*(vars()->map->size) = (int) ft_strlen(str);
	while (str)
	{
		if ((int) ft_strlen(str) != *(vars()->map->size))
			map_error("The map is not rectangular");
		if (str[0] != '1' || str[ft_strlen(str) - 2] != '1')
			map_error("Border should be a wall");
		prev_str = str;
		str = get_next_line(fd);
		if (!str)
			flag = 1;
		i = 0;
		while (prev_str[i] && flag && prev_str[i] != 10)
		{
			if (prev_str[i++] != '1')
				map_error("Border should be a wall");
		}
		free(prev_str);
		flag = 0;
	}
	return (str);
}

void	valid_elements(int fd, int i, int p_count, int e_count)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		i = -1;
		while (str[++i])
		{
			if (str[i] == 'P')
				p_count++;
			else if (str[i] == 'E')
				e_count++;
			else if (str[i] == 'C')
			(*(vars()->map->collectibles))++;
			else if (str[i] != '0' && str[i] != '1' && str[i] != 10)
				map_error("Valid elements are: 1, 0, C, P & E");
		}
		free(str);
		str = get_next_line(fd);
	}
	if (*(vars()->map->collectibles) < 1 || e_count > 1 || p_count < 1
		|| e_count < 1 || p_count > 1)
		map_error("You need at least one 'C' and exactly one 'P' and one 'E'");
}

bool	valid_syntax(char *file_name)
{
	int		len;
	int		fd;
	char	*str;

	len = ft_strlen(file_name);
	if (len < 4 || strcmp(file_name + len - 4, ".ber") != 0)
		map_error("Wrong file extension. Should be <.ber>");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		map_error("Error opening the file");
	str = valid_shape(fd, 0, 1);
	free(str);
	fd = open(file_name, O_RDONLY);
	valid_elements(fd, -1, 0, 0);
	ft_printf("Good map\n");
	close(fd);
	return (true);
}
// void	open_images()
// {
// 	return ;
// }

// void	print_map()
// {
// 	return ;
// }