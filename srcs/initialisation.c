/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:35:48 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/06 10:06:41 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data)
{
	data->map.map = NULL;
	data->map.ceiling_color_arr = NULL;
	data->map.south_texture = NULL;
	data->map.north_texture = NULL;
	data->map.floor_color_arr = NULL;
	data->map.west_texture = NULL;
	data->map.east_texture = NULL;
	data->map.position = false;
	data->move_speed = 0.15;
	data->rot_speed = 0.05;
	data->a_move = false;
	data->w_move = false;
	data->s_move = false;
	data->d_move = false;
	data->l_turn = false;
	data->r_turn = false;
	init_raycasting(data);
	init_texture(&data->e_txt);
	init_texture(&data->w_txt);
	init_texture(&data->n_txt);
	init_texture(&data->s_txt);
}

void	init_raycasting(t_data *data)
{
	data->pos_x = 0.0;
	data->pos_y = 0.0;
	data->dir_x = 0.0;
	data->dir_y = 0.0;
	data->plane_x = 0.0;
	data->plane_y = 0.0;
	data->camera = 0.0;
	data->ray_dir_x = 0.0;
	data->ray_dir_y = 0.0;
	data->delta_dist_x = 0.0;
	data->delta_dist_y = 0.0;
	data->grid_step_x = 0;
	data->grid_step_y = 0;
	data->side_dist_x = 0.0;
	data->side_dist_y = 0.0;
	data->ray_x = 0;
	data->ray_y = 0;
	data->wall_hit = 0;
	data->wall = 0;
	data->shortest_dist_wall_cam = 0.0;
	data->cos_rot_speed = cos(data->rot_speed);
	data->sin_rot_speed = sin(data->rot_speed);
	data->cos_rot_speed_neg = cos(-data->rot_speed);
	data->sin_rot_speed_neg = sin(-data->rot_speed);
}

void	init_texture(t_texture *texture)
{
	texture->img = NULL;
	texture->address = NULL;
	texture->height = 300;
	texture->width = 300;
	texture->bpp = 0;
	texture->line_length = 0;
	texture->endian = 0;
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		end_program(data, false, MLX_INIT_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WIDTH, HEIGHT, "Cub3d");
	if (!data->win_ptr)
		end_program(data, false, MLX_INIT_ERROR);
	data->main.img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->main.img)
		end_program(data, false, MLX_INIT_ERROR);
	data->main.address = mlx_get_data_addr(data->main.img, &data->main.bpp, \
	&data->main.line_length, &data->main.endian);
	if (!data->main.address)
		end_program(data, false, MLX_INIT_ERROR);
	load_texture(data, &data->e_txt, data->map.east_texture);
	load_texture(data, &data->n_txt, data->map.north_texture);
	load_texture(data, &data->w_txt, data->map.west_texture);
	load_texture(data, &data->s_txt, data->map.south_texture);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, on_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, on_keyrelease, data);
	mlx_loop_hook(data->mlx_ptr, mlx_key_loop, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	return (0);
}

void	load_texture(t_data *data, t_texture *texture, char *texture_path)
{
	texture->img = mlx_xpm_file_to_image(data->mlx_ptr, texture_path, \
	&texture->width, &texture->height);
	if (!texture->img)
		end_program(data, false, MLX_INIT_ERROR);
	texture->address = mlx_get_data_addr(texture->img, &texture->bpp, \
	&texture->line_length, &texture->endian);
	if (!texture->address)
		end_program(data, false, MLX_INIT_ERROR);
}
