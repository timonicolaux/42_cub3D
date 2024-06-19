/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:24:05 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/06 11:33:23 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	change_door_monitor(t_data *data)
{
	if (data->door_action == true)
	{
		if (data->map.map[(int)data->pos_y][(int)data->pos_x + 1] == 'D' || \
		data->map.map[(int)data->pos_y][(int)data->pos_x + 1] == 'O')
			change_door(&data->map.map[(int)data->pos_y][(int)data->pos_x + 1]);
		if (data->map.map[(int)data->pos_y][(int)data->pos_x - 1] == 'D' || \
		data->map.map[(int)data->pos_y][(int)data->pos_x - 1] == 'O')
			change_door(&data->map.map[(int)data->pos_y][(int)data->pos_x - 1]);
		if (data->map.map[(int)data->pos_y + 1][(int)data->pos_x] == 'D' || \
		data->map.map[(int)data->pos_y + 1][(int)data->pos_x] == 'O')
			change_door(&data->map.map[(int)data->pos_y + 1][(int)data->pos_x]);
		if (data->map.map[(int)data->pos_y - 1][(int)data->pos_x] == 'D' || \
		data->map.map[(int)data->pos_y - 1][(int)data->pos_x] == 'O')
			change_door(&data->map.map[(int)data->pos_y - 1][(int)data->pos_x]);
	}
}

void	change_door(char *value)
{
	if (*value == 'O')
		*value = 'D';
	else
		*value = 'O';
}

void	door_action(int keycode, t_data *data)
{
	if (keycode == XK_o)
		data->door_action = true;
}

void	free_animation(t_data *data)
{
	int	i;

	i = 0;
	while (i < ANIMATION_FRAMES)
	{
		if (data->anim.frames[i].img)
			mlx_destroy_image(data->mlx_ptr, data->anim.frames[i].img);
		i++;
	}
}
