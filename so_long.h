/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:19:13 by skillian          #+#    #+#             */
/*   Updated: 2021/11/29 17:17:16 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

# define EMPTY			'0'
# define WALL			'1'
# define COLLECT		'C'
# define EXIT			'E'
# define PLAYER			'P'

# define PATH_WALL		"./xpm_images/wall.xpm"
# define PATH_COLLECT	"./xpm_images/collect.xpm"
# define PATH_EXIT		"./xpm_images/exit.xpm"
# define PATH_PLAYER	"./xpm_images/cat64.xpm"
# define PATH_MAINFIELD	"./xpm_images/mainfield.xpm"

# define IMG_LENGHT		64
# define IMG_WIDTH		64

# define UP				13
# define DOWN			1
# define LEFT			0
# define RIGHT			2
# define ESC			53

typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

typedef struct s_window
{
	void		*reference;
	t_vector	size;
}				t_window;

typedef struct s_image
{
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_map
{	
	char	**red_map;
	int		x_map;
	int		y_map;
}				t_map;

typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		wall;
	t_image		cat;
	t_image		collect;
	t_image		exit;
	t_image		background;
	t_vector	cat_position;
	t_map		*map;
	int			counter_collected;
	int			max_collectables;
	int			counter_moves;
}				t_program;

void		read_xy_map(t_map *map, char *argv[]);
int			read_map_lines(t_map *map, char *argv[]);
void		load_images(t_program *program);
void		interpret_mapfield_and_print(t_map *map, t_program *program, \
			int x_scan, int y_scan);
void		intepretor(t_map *map, t_program *program, int x_scan, int y_scan);
void		my_put_img(t_program *program, void *img_ref, \
			int x_scan, int y_scan);
void		max_one_player(t_map *map, int x_scan, int y_scan);

int			key_input(int key, t_program *program);
void		player_start_position(t_program *program, int x_scan, int y_scan);
void		move_player(int move_x, int move_y, t_program *program);
int			check_surroundings(int move_x, int move_y, t_program program);
void		check_for_collectable(t_program *program);
int			check_for_exit(t_program program);

int			error_character_check(t_map *map, t_program *program, \
			int y_scan, int x_scan);
void		error_wall_frame_check(t_map *map, t_program *program);
int			error_messages_and_exit(int issue);
void		error_ber_type_checker(char *argv);
void		error_map_lines_checker(t_map *map, char *map_line);
void		error_min_one_E_P_C_checker(t_map *map, int x_scan, int y_scan);

void		free_all_allocated(t_program *program, int exit_status);

t_window	ft_new_window(void *mlx, int widht, int height, char *name);
t_image		ft_new_wall(void *mlx, char *path);
t_image		ft_print_cat(void *mlx, char *path);
t_image		ft_print_collect(void *mlx, char *path);
t_image		ft_print_exit(void *mlx, char *path);
t_image		ft_print_mainfield(void *mlx, char *path);

#endif