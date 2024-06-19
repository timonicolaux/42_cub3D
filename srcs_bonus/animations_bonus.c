/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:09:43 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/10 14:20:41 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	init_path_frame_array(t_data *data)
{
	data->anim.path_frame = ft_calloc(ANIMATION_FRAMES + 1, sizeof(char *));
	if (!data->anim.path_frame)
		free_data(data, true, MALLOC_ERROR, NULL);
	data->anim.path_frame[0] = "assets/animation_J/J01.xpm";
	data->anim.path_frame[1] = "assets/animation_J/J02.xpm";
	data->anim.path_frame[2] = "assets/animation_J/J03.xpm";
	data->anim.path_frame[3] = "assets/animation_J/J04.xpm";
	data->anim.path_frame[4] = "assets/animation_J/J05.xpm";
	data->anim.path_frame[5] = "assets/animation_J/J06.xpm";
	data->anim.path_frame[6] = "assets/animation_J/J07.xpm";
	data->anim.path_frame[7] = "assets/animation_J/J08.xpm";
	data->anim.path_frame[8] = "assets/animation_J/J09.xpm";
	data->anim.path_frame[9] = "assets/animation_J/J10.xpm";
	data->anim.path_frame[10] = "assets/animation_J/J11.xpm";
	data->anim.path_frame[11] = "assets/animation_J/J12.xpm";
	data->anim.path_frame[12] = "assets/animation_J/J13.xpm";
	data->anim.path_frame[13] = "assets/animation_J/J14.xpm";
	data->anim.path_frame[14] = "assets/animation_J/J15.xpm";
	data->anim.path_frame[15] = "assets/animation_J/J16.xpm";
	data->anim.path_frame[16] = "assets/animation_J/J17.xpm";
	data->anim.path_frame[17] = "assets/animation_J/J18.xpm";
}

void	load_animation(t_data *data)
{
	int	i;

	i = 0;
	while (i < ANIMATION_FRAMES)
	{
		load_texture(data, &data->anim.frames[i], data->anim.path_frame[i]);
		i++;
	}
}

void	init_animation(t_data *data)
{
	int	i;

	i = 0;
	data->anim.current_frame = 0;
	data->anim.frame_time = 100;
	data->anim.last_update_time = 0;
	data->anim.path_frame = NULL;
	data->anim.frames = NULL;
	data->anim.frames = malloc(ANIMATION_FRAMES * sizeof(t_texture));
	if (!data->anim.frames)
		free_data(data, true, MALLOC_ERROR, NULL);
	init_path_frame_array(data);
	while (i < ANIMATION_FRAMES)
	{
		init_texture(&data->anim.frames[i]);
		i++;
	}
}

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	update_animation(t_animation *anim)
{
	size_t	current_time;

	current_time = get_time();
	if (current_time - anim->last_update_time > anim->frame_time)
	{
		anim->current_frame = (anim->current_frame + 1) % ANIMATION_FRAMES;
		anim->last_update_time = current_time;
	}
}
