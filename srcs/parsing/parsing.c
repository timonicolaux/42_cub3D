/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:45:32 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/07 14:54:32 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_file(char *file, t_data *data)
{
	char	*line;
	int		fd;
	int		found_map;

	found_map = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_data(data, true, OPENING_FILE_ERROR, NULL);
	while (42)
	{
		if (found_map)
			break ;
		line = get_next_line(fd, data);
		if (!line)
			break ;
		parse_textures(line, data, &found_map);
		free(line);
	}
	parse_floor_ceiling(data);
	close(fd);
	store_map(data, file);
	return (0);
}

int	parse_textures(char *line, t_data *data, int *found_map)
{
	int	i;

	i = 0;
	while (line[i])
	{
		while (line[i] && ft_strchr(SPACES, line[i]))
			i++;
		if (!check_text_type(data, line, i))
			return (0);
		else if (line[i] && !data->map.ceiling_color_arr && line[i] != '\n' && \
		!ft_strchr(SPACES, line[i]) && line[i] != '1')
			free_data(data, true, INVALID_CUB_FILE, line);
		else if (data->map.ceiling_color_arr && data->map.east_texture && \
		data->map.floor_color_arr && data->map.north_texture && \
		data->map.south_texture && data->map.west_texture && line[i] == '1')
			return (*found_map = 1, 0);
		else if (data->map.ceiling_color_arr && data->map.east_texture && \
		data->map.floor_color_arr && data->map.north_texture && \
		data->map.south_texture && data->map.west_texture && \
		!ft_strchr(SPACES, line[i]) && line[i] != '1')
			free_data(data, true, INVALID_CUB_FILE, line);
		i++;
	}
	return (0);
}

int	check_text_type(t_data *data, char *line, int i)
{
	if (!line[i])
		return (0);
	if (line[i] == 'N' && line[i + 1] == 'O')
		return (parse_one_texture(line, data, "NO", i + 2));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (parse_one_texture(line, data, "EA", i + 2));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (parse_one_texture(line, data, "WE", i + 2));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (parse_one_texture(line, data, "SO", i + 2));
	else if (line[i] == 'F')
		return (parse_color(i + 1, line, data, "F"));
	else if (line[i] == 'C')
		return (parse_color(i + 1, line, data, "C"));
	return (1);
}

void	parse_floor_ceiling(t_data *data)
{
	if (!data->map.north_texture || !data->map.south_texture || \
	!data->map.east_texture || !data->map.west_texture)
		free_data(data, true, INVALID_CUB_FILE, NULL);
	data->map.floor_color = rgb_converter(data->map.floor_color_arr[0], \
	data->map.floor_color_arr[1], data->map.floor_color_arr[2]);
	data->map.ceiling_color = rgb_converter(data->map.ceiling_color_arr[0], \
	data->map.ceiling_color_arr[1], data->map.ceiling_color_arr[2]);
}
