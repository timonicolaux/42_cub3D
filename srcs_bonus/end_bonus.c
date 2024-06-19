/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:48:00 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/07 15:14:34 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	end_program(t_data *data, bool exit_success, char *message)
{
	if (message)
		ft_printf("Error\n%s\n", message);
	free_mlx(data, false, NULL);
	free_data(data, false, NULL, NULL);
	if (exit_success)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

int	close_window(t_data *data)
{
	free_mlx(data, false, NULL);
	free_data(data, false, NULL, NULL);
	exit(EXIT_SUCCESS);
}

void	free_mlx(t_data *data, bool to_exit, char *message)
{
	if (message)
		ft_printf("Error\n%s\n", message);
	if (data->s_txt.img)
		mlx_destroy_image(data->mlx_ptr, data->s_txt.img);
	if (data->n_txt.img)
		mlx_destroy_image(data->mlx_ptr, data->n_txt.img);
	if (data->e_txt.img)
		mlx_destroy_image(data->mlx_ptr, data->e_txt.img);
	if (data->w_txt.img)
		mlx_destroy_image(data->mlx_ptr, data->w_txt.img);
	if (data->door_open_txt.img)
		mlx_destroy_image(data->mlx_ptr, data->door_open_txt.img);
	if (data->door_closed_txt.img)
		mlx_destroy_image(data->mlx_ptr, data->door_closed_txt.img);
	free_animation(data);
	if (data->main.img)
		mlx_destroy_image(data->mlx_ptr, data->main.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	if (to_exit)
		exit(EXIT_FAILURE);
}

void	free_data(t_data *data, bool to_exit, char *message, char *str)
{
	if (message)
		ft_printf("Error\n%s\n", message);
	if (data->map.ceiling_color_arr)
		free(data->map.ceiling_color_arr);
	if (data->map.floor_color_arr)
		free(data->map.floor_color_arr);
	if (data->map.north_texture)
		free(data->map.north_texture);
	if (data->map.south_texture)
		free(data->map.south_texture);
	if (data->map.east_texture)
		free(data->map.east_texture);
	if (data->map.west_texture)
		free(data->map.west_texture);
	if (data->map.map)
		free_double_array(data->map.map);
	free_double_and_single_arr(NULL, str, data->minimap.map);
	if (data->anim.path_frame)
		free(data->anim.path_frame);
	if (data->anim.frames)
		free(data->anim.frames);
	if (to_exit)
		exit(EXIT_FAILURE);
}

void	free_double_and_single_arr(char *single_arr_1, char *single_arr_2, \
char **double_arr)
{
	if (single_arr_1)
		free(single_arr_1);
	if (single_arr_2)
		free(single_arr_2);
	if (double_arr)
		free_double_array(double_arr);
}
