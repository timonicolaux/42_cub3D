/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:16:09 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/28 13:08:59 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_camera_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * data->cos_rot_speed_neg - data->dir_y * \
	data->sin_rot_speed_neg;
	data->dir_y = old_dir_x * data->sin_rot_speed_neg + data->dir_y * \
	data->cos_rot_speed_neg;
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * data->cos_rot_speed_neg - data->plane_y * \
	data->sin_rot_speed_neg;
	data->plane_y = old_plane_x * data->sin_rot_speed_neg + data->plane_y * \
	data->cos_rot_speed_neg;
}

int	move_monitor(t_data *data)
{
	if (data->a_move == true)
		move_a(data);
	if (data->w_move == true)
		move_w(data);
	if (data->s_move == true)
		move_s(data);
	if (data->d_move == true)
		move_d(data);
	if (data->l_turn == true)
		turn_camera_left(data);
	if (data->r_turn == true)
		turn_camera_right(data);
	return (0);
}

int	mlx_key_loop(t_data *data)
{
	move_monitor(data);
	raycasting(data);
	return (0);
}

int	on_keyrelease(int keycode, t_data *data)
{
	if (data->a_move && keycode == XK_a)
		data->a_move = false;
	if (data->w_move && keycode == XK_w)
		data->w_move = false;
	if (data->s_move && keycode == XK_s)
		data->s_move = false;
	if (data->d_move && keycode == XK_d)
		data->d_move = false;
	if (data->l_turn && keycode == XK_Left)
		data->l_turn = false;
	if (data->r_turn && keycode == XK_Right)
		data->r_turn = false;
	return (0);
}

int	on_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (!data->a_move && keycode == XK_a)
		data->a_move = true;
	if (!data->w_move && keycode == XK_w)
		data->w_move = true;
	if (!data->s_move && keycode == XK_s)
		data->s_move = true;
	if (!data->d_move && keycode == XK_d)
		data->d_move = true;
	if (!data->l_turn && keycode == XK_Left)
		data->l_turn = true;
	if (!data->r_turn && keycode == XK_Right)
		data->r_turn = true;
	return (0);
}
