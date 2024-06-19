/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:22:28 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/06 13:27:09 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	rgb_converter(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->main.address + (y * data->main.line_length + x * \
	(data->main.bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_pixel_color(t_texture texture, int x, int y)
{
	int				offset;
	unsigned int	color;

	if (x < 0 || x >= texture.width || y < 0 || y >= texture.height)
		return (0);
	offset = (y * texture.line_length + x * (texture.bpp / 8));
	color = *(unsigned int *)(texture.address + offset);
	return (color);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

int	length_double_arr(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (array[i])
		i++;
	return (i);
}
