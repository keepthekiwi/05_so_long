/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:42:57 by skillian          #+#    #+#             */
/*   Updated: 2021/12/12 14:31:17 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all_allocated(t_program *program, int exit_status)
{
	int	i;

	i = 0;
	if (program->map->red_map[0])
	{
		while (program->map->red_map[i])
		{
			free(program->map->red_map[i]);
			i++;
		}
	}
	free(program->map->red_map);
	mlx_destroy_window(program->mlx, program->window.reference);
	mlx_destroy_image(program->mlx, program->wall.reference);
	mlx_destroy_image(program->mlx, program->cat.reference);
	mlx_destroy_image(program->mlx, program->collect.reference);
	mlx_destroy_image(program->mlx, program->exit.reference);
	mlx_destroy_image(program->mlx, program->background.reference);
	mlx_destroy(program->mlx);
	if (exit_status == EXIT_SUCCESS)
		exit(exit_status);
}
