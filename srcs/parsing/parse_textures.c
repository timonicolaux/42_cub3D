/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:46:21 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/10 14:50:52 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_one_texture(char *line, t_data *data, char *str, int i)
{
	int		length;
	char	*texture;

	length = 0;
	if (!ft_strchr(SPACES, line[i]))
		free_data(data, true, INVALID_CUB_FILE, line);
	while (line[i] && ft_strchr(SPACES, line[i]))
		i++;
	while (line[i] && line[i] != '\n' && !ft_strchr(SPACES, line[i]))
	{
		i++;
		length++;
	}
	texture = malloc((length + 1) * sizeof(char));
	if (!texture)
		free_data(data, true, MALLOC_ERROR, line);
	fill_texture(i - length, line, texture, data);
	store_texture(texture, data, str, line);
	return (0);
}

void	fill_texture(int i, char *line, char *texture, t_data *data)
{
	int	j;

	j = 0;
	while (line[i] && line[i] != '\n' && !ft_strchr(SPACES, line[i]))
		texture[j++] = line[i++];
	texture[j] = '\0';
	while (line[i] && line[i] != '\n' && ft_strchr(SPACES, line[i]))
		i++;
	if (line[i] != '\n' && line[i] != '\0')
	{
		free(texture);
		free_data(data, true, INVALID_CUB_FILE, line);
	}
}

char	**convert_in_color_arr_split(char *color_str, t_data *data, char *line)
{
	char	**split_array;

	split_array = ft_split(color_str, ',');
	if (!split_array || length_double_arr(split_array) != 3)
	{
		free_double_and_single_arr(color_str, line, split_array);
		free_data(data, true, INVALID_CUB_FILE, NULL);
	}
	return (split_array);
}

void	convert_in_color_arr(char *color_str, t_data *data, char *line, \
int **color_arr)
{
	char	**split_array;
	int		i;

	i = -1;
	split_array = convert_in_color_arr_split(color_str, data, line);
	*color_arr = malloc(3 * sizeof(int));
	if (!*color_arr)
	{
		free_double_and_single_arr(color_str, line, split_array);
		free_data(data, true, MALLOC_ERROR, NULL);
	}
	while (split_array[++i])
	{
		if ((ft_atoi(split_array[i]) == 0 && find_zero(split_array[i])) || \
		check_rgb_value(ft_atoi(split_array[i])) || \
		find_zero(split_array[i]) == 2)
		{
			free_double_and_single_arr(color_str, NULL, split_array);
			free_data(data, true, INVALID_CUB_FILE, line);
		}
		(*color_arr)[i] = ft_atoi(split_array[i]);
	}
	free_double_and_single_arr(color_str, NULL, split_array);
}

int	store_texture(char *texture, t_data *data, char *str, char *line)
{
	if (!ft_strncmp(str, "NO", 3) && !data->map.north_texture)
		data->map.north_texture = texture;
	else if (!ft_strncmp(str, "EA", 3) && !data->map.east_texture)
		data->map.east_texture = texture;
	else if (!ft_strncmp(str, "WE", 3) && !data->map.west_texture)
		data->map.west_texture = texture;
	else if (!ft_strncmp(str, "SO", 3) && !data->map.south_texture)
		data->map.south_texture = texture;
	else if (!ft_strncmp(str, "F", 2) && !data->map.floor_color_arr && \
	!check_color_str(data, texture, line))
		convert_in_color_arr(texture, data, line, &data->map.floor_color_arr);
	else if (!ft_strncmp(str, "C", 2) && !data->map.ceiling_color_arr && \
	!check_color_str(data, texture, line))
		convert_in_color_arr(texture, data, line, &data->map.ceiling_color_arr);
	else
	{
		free(texture);
		free_data(data, true, INVALID_CUB_FILE, line);
	}
	return (0);
}
