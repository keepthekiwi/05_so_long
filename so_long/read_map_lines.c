/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:22:26 by skillian          #+#    #+#             */
/*   Updated: 2021/11/29 22:03:42 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map_lines(t_map *map, char *argv[])
/* read the map line by line and saves it as a pointer in red_map [y] */
{
	int		fd;
	int		y;

	map->red_map = ft_calloc(map->y_map + 1, sizeof(*map->red_map));
	if (!map->red_map)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (error_messages_and_exit(7));
	y = 0;
	while (y < map->y_map)
	{
		map->red_map [y] = get_next_line(fd);
		y++;
	}
	map->red_map[y] = NULL;
	close(fd);
	return (0);
}
