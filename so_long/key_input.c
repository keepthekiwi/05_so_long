/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:28:01 by skillian          #+#    #+#             */
/*   Updated: 2021/11/30 16:21:58 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_input(int key, t_program *program)
{
	if (key == ESC)
	{
		printf("Psycho Cat is sad! You have exited the game...\n");
		free_all_allocated(program, EXIT_SUCCESS);
	}
	if (key == UP && check_surroundings(0, -1, *program))
		move_player(0, -1, program);
	if (key == DOWN && check_surroundings(0, +1, *program))
		move_player(0, +1, program);
	if (key == LEFT && check_surroundings(-1, 0, *program))
		move_player(-1, 0, program);
	if (key == RIGHT && check_surroundings(+1, 0, *program))
		move_player(+1, 0, program);
	check_for_collectable(program);
	if (check_for_exit(*program))
		free_all_allocated(program, EXIT_SUCCESS);
	return (0);
}

void	move_player(int move_x, int move_y, t_program *program)
{
	if (program->map->red_map[program->cat_position.y][program->cat_position.x] \
		!= EXIT)
		mlx_put_image_to_window(program->mlx, program->window.reference, \
			program->background.reference, \
			(program->cat_position.x * IMG_LENGHT), \
			(program->cat_position.y * IMG_WIDTH));
	else
		mlx_put_image_to_window(program->mlx, program->window.reference,
			program->exit.reference, (program->cat_position.x * IMG_LENGHT), \
			(program->cat_position.y * IMG_WIDTH));
	program->cat_position.x = program->cat_position.x + move_x;
	program->cat_position.y = program->cat_position.y + move_y;
	if (program->map->red_map[program->cat_position.y][program->cat_position.x] \
		!= EXIT)
	{
		mlx_put_image_to_window(program->mlx, program->window.reference, \
			program->background.reference, \
			(program->cat_position.x * IMG_LENGHT), \
			(program->cat_position.y * IMG_WIDTH));
	}
	mlx_put_image_to_window(program->mlx, program->window.reference, \
		program->cat.reference, (program->cat_position.x * IMG_LENGHT), \
		(program->cat_position.y * IMG_WIDTH));
	program->counter_moves++;
	printf("move #%i\n", program->counter_moves);
}

int	check_surroundings(int move_x, int move_y, t_program program)
{
	program.cat_position.x = program.cat_position.x + move_x;
	program.cat_position.y = program.cat_position.y + move_y;
	if (program.map->red_map[program.cat_position.y][program.cat_position.x] \
		== WALL)
		return (0);
	else
		return (1);
}

void	check_for_collectable(t_program *program)
{
	if (program->map->red_map[program->cat_position.y][program->cat_position.x] \
		== COLLECT)
	{
		program->counter_collected++;
		program->map->red_map[program->cat_position.y][program->cat_position.x] \
			= EMPTY;
		printf("diamond #%i out of %i\n", program->counter_collected, \
		program->max_collectables);
	}
}

int	check_for_exit(t_program program)
{
	if (program.map->red_map[program.cat_position.y][program.cat_position.x] \
		== EXIT
		&& program.counter_collected == program.max_collectables)
	{
		printf("CONGRATS! YOU WON! NOW PAY ME 2$\n");
		return (1);
	}
	return (0);
}
