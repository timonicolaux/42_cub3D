/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:19:25 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/30 13:23:45 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

void	fill_black_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 11)
	{
		while (j < data->minimap.num_square_x)
		{
			data->minimap.map[i][j] = 'B';
			j++;
		}
		data->minimap.map[i][j] = '\0';
		j = 0;
		i++;
	}
}

void	fill_up(t_data *data, int x_big, int x)
{
	int	y;
	int	y_big;

	y = 5;
	y_big = (int)data->pos_y;
	while (y_big >= 0 && y >= 0)
	{
		if (ft_strchr(CHARACTERS_MM, data->map.map[y_big][x_big]))
			data->minimap.map[y][x] = data->map.map[y_big][x_big];
		y_big--;
		y--;
	}
}

void	fill_down(t_data *data, int x_big, int x)
{
	int	y;
	int	y_big;

	y = 6;
	y_big = (int)data->pos_y + 1;
	while ((y_big < data->map.num_lines) && (y < 11))
	{
		if (ft_strchr(CHARACTERS_MM, data->map.map[y_big][x_big]))
			data->minimap.map[y][x] = data->map.map[y_big][x_big];
		y_big++;
		y++;
	}
}

void	fill_minimap(t_data *data)
{
	int	x;
	int	x_big;
	int	y_big;

	x = data->minimap.num_square_x >> 1;
	x_big = (int)data->pos_x;
	y_big = (int)data->pos_y;
	while (x_big > 0 && x > 0)
	{
		x_big--;
		x--;
	}
	while ((x_big < (int)ft_strlen(data->map.map[y_big])) && \
	(x <= data->minimap.num_square_x))
	{
		fill_up(data, x_big, x);
		fill_down(data, x_big, x);
		x_big++;
		x++;
	}
	data->minimap.map[5][data->minimap.num_square_x >> 1] = 'P';
}
