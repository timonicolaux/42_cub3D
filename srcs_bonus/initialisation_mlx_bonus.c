/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_mlx_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:51:58 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/05 16:14:29 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

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
	load_textures_animations(data);
	data->last_mouse_x = data->mouse_x;
	mlx_hook(data->win_ptr, 6, 1L << 6, mouse_hook, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, on_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, on_keyrelease, data);
	mlx_loop_hook(data->mlx_ptr, mlx_key_loop, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	return (0);
}

void	load_textures_animations(t_data *data)
{
	load_texture(data, &data->e_txt, data->map.east_texture);
	load_texture(data, &data->n_txt, data->map.north_texture);
	load_texture(data, &data->w_txt, data->map.west_texture);
	load_texture(data, &data->s_txt, data->map.south_texture);
	load_texture(data, &data->door_open_txt, "./assets/door_open.xpm");
	load_texture(data, &data->door_closed_txt, "./assets/door_closed.xpm");
	load_animation(data);
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
