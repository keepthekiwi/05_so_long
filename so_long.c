/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:10:20 by skillian          #+#    #+#             */
/*   Updated: 2021/12/12 14:33:04 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map		map;
	t_program	program;

	if (argc != 2)
		return (0);
	error_ber_type_checker(argv[1]);
	read_xy_map(&map, argv);
	read_map_lines(&map, argv);
	program.map = &map;
	program.counter_collected = 0;
	program.max_collectables = 0;
	program.counter_moves = 0;
	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, (map.x_map * IMG_LENGHT), \
		(map.y_map * IMG_WIDTH), "Psycho Cat");
	load_images(&program);
	error_min_one_E_P_C_checker(&map, 0, 0);
	error_wall_frame_check(&map, &program);
	max_one_player(&map, 0, 0);
	interpret_mapfield_and_print(&map, &program, 0, 0);
	mlx_key_hook(program.window.reference, key_input, &program);
	mlx_loop(program.mlx);
	free_all_allocated(&program, EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	load_images(t_program *program)
{
	program->wall = ft_new_wall(program->mlx, "./xpm_images/wall.xpm");
	program->collect = ft_print_collect(program->mlx, PATH_COLLECT);
	program->background = ft_print_mainfield(program->mlx, PATH_MAINFIELD);
	program->cat = ft_print_cat(program->mlx, PATH_PLAYER);
	program->exit = ft_print_exit(program->mlx, PATH_EXIT);
}
