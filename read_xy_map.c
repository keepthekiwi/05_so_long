/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_xy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:42:58 by skillian          #+#    #+#             */
/*   Updated: 2021/11/29 22:04:15 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_xy_map(t_map *map, char *argv[])
/* Figure out x and y of map */
{
	int		fd;
	char	*map_line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_messages_and_exit(7);
	map->x_map = 0;
	map->y_map = 0;
	map->red_map = NULL;
	while (1)
	{
		map_line = get_next_line(fd);
		if (map_line == NULL)
			break ;
		error_map_lines_checker(map, map_line);
		if (!map->x_map)
			map->x_map = ft_strlen(map_line) - 1;
		map->y_map++;
		free(map_line);
	}
	close(fd);
}

void	error_map_lines_checker(t_map *map, char *map_line)
/* checks if map is regtangle */
{
	int	line_error_checker;

	if (map->x_map)
	{
		line_error_checker = ft_strlen(map_line) - 1;
		if (line_error_checker != map->x_map)
		{
			free(map_line);
			error_messages_and_exit(5);
		}
	}
}
