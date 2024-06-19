/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:43:31 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/10 14:25:05 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	init_minimap(t_minimap *minimap)
{
	minimap->height = (int)HEIGHT * 0.25;
	minimap->width = (int)WIDTH * 0.25;
	minimap->square_size = (int)minimap->height / 11;
	minimap->num_square_x = (int)minimap->width / minimap->square_size;
	minimap->map = NULL;
}

void	display_square_line(t_data *data, char map_element, int x, int y)
{
	int	i;
	int	color_int;

	i = 0;
	color_int = 0;
	if (ft_strchr(CHARACTERS, map_element) && map_element != '\0' && \
	map_element != 'D' && map_element != 'O')
		color_int = 15526573;
	else if (map_element == '1')
		color_int = 13529668;
	else if (map_element == 'P')
		color_int = 41727;
	else if (map_element == 'D')
		color_int = 16711680;
	else if (map_element == 'O')
		color_int = 583680;
	else
		color_int = 0;
	while (i < data->minimap.square_size + 1)
	{
		my_mlx_pixel_put(data, x, y, color_int);
		i++;
		y++;
	}
}

void	display_minimap(t_data *data)
{
	t_display_minimap	s;
	static double		pos_x_cpy;
	static double		pos_y_cpy;

	ft_memset(&s, 0, sizeof(t_display_minimap));
	s.x = WIDTH * 0.75;
	create_minimap(data, &pos_x_cpy, &pos_y_cpy);
	while (s.x < WIDTH)
	{
		while (s.y < HEIGHT * 0.25)
		{
			display_square_line(data, data->minimap.map[s.i][s.j], s.x, s.y);
			s.y += data->minimap.square_size + 1;
			(s.i)++;
		}
		(s.col_count)++;
		if (s.col_count == data->minimap.square_size)
		{
			(s.j)++;
			s.col_count = 0;
		}
		s.y = 0;
		s.i = 0;
		(s.x)++;
	}
}

void	create_minimap(t_data *data, double *pos_x_cpy, double *pos_y_cpy)
{
	int	i;

	i = 0;
	if (data->minimap.map == NULL || *pos_x_cpy != data->pos_x \
	|| *pos_y_cpy != data->pos_y || data->door_action)
	{
		if (data->minimap.map)
			free_double_array(data->minimap.map);
		*pos_x_cpy = data->pos_x;
		*pos_y_cpy = data->pos_y;
		data->minimap.map = ft_calloc(12, sizeof(char *));
		if (!data->minimap.map)
			end_program(data, false, MALLOC_ERROR);
		while (i < 11)
		{
			data->minimap.map[i] = malloc(sizeof(char) * \
			(data->minimap.num_square_x + 1));
			if (!data->minimap.map[i])
				end_program(data, false, MALLOC_ERROR);
			i++;
		}
		data->minimap.map[11] = NULL;
		fill_black_minimap(data);
		fill_minimap(data);
	}
}
