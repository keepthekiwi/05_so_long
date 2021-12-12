/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 19:42:15 by skillian          #+#    #+#             */
/*   Updated: 2021/11/30 20:03:45 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define CHARACTERS "0P1EC"

int	error_character_check(t_map *map, t_program *program, \
	int y_scan, int x_scan)
/* check if just {'0','1','C','E','P'} are in the map */
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (map->red_map[y_scan][x_scan] == CHARACTERS[i])
			return (0);
		i++;
	}
	free_all_allocated(program, EXIT_FAILURE);
	return (error_messages_and_exit(2));
}

void	error_wall_frame_check(t_map *map, t_program *program)
{
	int	x_check;
	int	y_check;

	x_check = 0;
	y_check = 0;
	while (y_check < map->y_map)
	{
		if (map->red_map[y_check][0] != '1' ||
			map->red_map[y_check][map->x_map - 1] != '1')
		{
			free_all_allocated(program, EXIT_FAILURE);
			error_messages_and_exit(3);
		}
		y_check++;
	}
	while (x_check < map->x_map)
	{
		if (map->red_map[0][x_check] != '1' ||
			map->red_map[map->y_map - 1][x_check] != '1')
		{
			free_all_allocated(program, EXIT_FAILURE);
			error_messages_and_exit(4);
		}
		x_check++;
	}
}

void	error_ber_type_checker(char *argv)
/* check if file is .ber */
{
	int		len;
	char	*origin;

	len = ft_strlen(argv);
	if (len < 4)
		error_messages_and_exit(6);
	origin = ft_substr(argv, (len - 4), len);
	if (ft_strncmp(origin, ".ber\0", 5))
	{
		free(origin);
		error_messages_and_exit(6);
	}
	free(origin);
}

void	error_min_one_E_P_C_checker(t_map *map, int x_scan, int y_scan)
{
	bool	min_one_E;
	bool	min_one_P;
	bool	min_one_C;

	min_one_E = false;
	min_one_P = false;
	min_one_C = false;
	while (y_scan < map->y_map)
	{
		while (x_scan < map->x_map)
		{	
			if (map->red_map[y_scan][x_scan] == COLLECT && min_one_C == false)
				min_one_C = true;
			if (map->red_map[y_scan][x_scan] == PLAYER && min_one_P == false)
				min_one_P = true;
			if (map->red_map[y_scan][x_scan] == EXIT && min_one_E == false)
				min_one_E = true;
			x_scan++;
		}
		y_scan++;
		x_scan = 0;
	}
	if (min_one_E == false || min_one_P == false || min_one_C == false)
		error_messages_and_exit(1);
}

int	error_messages_and_exit(int issue)
{
	if (issue == 1)
		printf("Error\nGive me min one Psycho Cat, Exit and Collectable\n");
	if (issue == 2)
		printf("Error\nMap contains other than the 5 characters.\n");
	if (issue == 3)
		printf("Error\nPlease sourround the map fully with WALLS.\n");
	if (issue == 4)
		printf("Error\nPlease sourround the map fully with WALLS.\n");
	if (issue == 5)
		printf("Error\nPsycho Cat doesnt care about your stupid map format.\n");
	if (issue == 6)
		printf("Error\nPlease change the filetype to .ber.\n");
	if (issue == 7)
		printf("Error\nNot a valid file\n");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
