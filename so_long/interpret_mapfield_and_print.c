/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_mapfield_and_print.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:44:27 by skillian          #+#    #+#             */
/*   Updated: 2021/11/28 21:29:30 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	interpret_mapfield_and_print(t_map *map, t_program *program, \
		int x_scan, int y_scan)
{
	while (y_scan < map->y_map)
	{
		while (x_scan < map->x_map)
		{
			error_character_check(map, program, y_scan, x_scan);
			my_put_img(program, program->background.reference, x_scan, y_scan);
			intepretor(map, program, x_scan, y_scan);
			x_scan++;
		}
		y_scan++;
		x_scan = 0;
	}
}

void	intepretor(t_map *map, t_program *program, int x_scan, int y_scan)
{
	if (map->red_map[y_scan][x_scan] == WALL)
		my_put_img(program, program->wall.reference, x_scan, y_scan);
	if (map->red_map[y_scan][x_scan] == COLLECT)
	{	
		my_put_img(program, program->collect.reference, x_scan, y_scan);
		program->max_collectables++;
	}
	if (map->red_map[y_scan][x_scan] == PLAYER)
	{
		player_start_position(program, x_scan, y_scan);
		my_put_img(program, program->cat.reference, x_scan, y_scan);
	}
	if (map->red_map[y_scan][x_scan] == EXIT)
		my_put_img(program, program->exit.reference, x_scan, y_scan);
}

void	my_put_img(t_program *program, void *img_ref, int x_scan, int y_scan)
{
	mlx_put_image_to_window(program->mlx, program->window.reference, \
		img_ref, (x_scan * IMG_LENGHT), (y_scan * IMG_WIDTH));
}

void	player_start_position(t_program *program, int x_scan, int y_scan)
{
	program->cat_position.x = x_scan;
	program->cat_position.y = y_scan;
}

void	max_one_player(t_map *map, int x_scan, int y_scan)
{
	bool	only_one_player;

	only_one_player = true;
	while (y_scan < map->y_map)
	{
		while (x_scan < map->x_map)
		{
			if (map->red_map[y_scan][x_scan] == PLAYER \
				&& only_one_player == false)
				map->red_map[y_scan][x_scan] = '0';
			if (map->red_map[y_scan][x_scan] == PLAYER)
				only_one_player = false;
			x_scan++;
		}
		y_scan++;
		x_scan = 0;
	}
}
