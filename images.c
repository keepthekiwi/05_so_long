/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:25:16 by skillian          #+#    #+#             */
/*   Updated: 2021/11/28 21:46:12 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	ft_new_wall(void *mlx, char *path)
/* mlx functions for the image */
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, \
		&img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

t_image	ft_print_cat(void *mlx, char *path)
{
	t_image	cat;

	cat.reference = mlx_xpm_file_to_image(mlx, path, &cat.size.x, &cat.size.y);
	cat.pixels = mlx_get_data_addr(cat.reference, \
		&cat.bits_per_pixel, &cat.line_size, &cat.endian);
	return (cat);
}

t_image	ft_print_collect(void *mlx, char *path)
{
	t_image	collect;

	collect.reference = mlx_xpm_file_to_image(mlx, path, \
		&collect.size.x, &collect.size.y);
	collect.pixels = mlx_get_data_addr(collect.reference, \
		&collect.bits_per_pixel, &collect.line_size, &collect.endian);
	return (collect);
}

t_image	ft_print_exit(void *mlx, char *path)
{
	t_image	exit;

	exit.reference = mlx_xpm_file_to_image(mlx, path, \
		&exit.size.x, &exit.size.y);
	exit.pixels = mlx_get_data_addr(exit.reference, \
		&exit.bits_per_pixel, &exit.line_size, &exit.endian);
	return (exit);
}

t_image	ft_print_mainfield(void *mlx, char *path)
{
	t_image	mainfield;

	mainfield.reference = mlx_xpm_file_to_image(mlx, path, \
		&mainfield.size.x, &mainfield.size.y);
	mainfield.pixels = mlx_get_data_addr(mainfield.reference, \
		&mainfield.bits_per_pixel, &mainfield.line_size, &mainfield.endian);
	return (mainfield);
}
