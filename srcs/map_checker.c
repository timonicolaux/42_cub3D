/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:15:09 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/06 15:13:56 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_file_extension(char *file_path)
{
	int	i;

	i = 0;
	while (file_path[i] && file_path[i] != '.')
		i++;
	file_path += i;
	if (ft_strncmp(file_path, ".cub", 5))
	{
		ft_printf("Bad file extension\n");
		return (1);
	}
	else
		return (0);
}

int	map_checker(t_data *data, char **map, int nb_lines)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (i == 0 || i == nb_lines)
		{
			while (map[i][j] && map[i][j] != '\n')
			{
				if (!ft_strchr(SPACES, map[i][j]) && map[i][j] != '1')
					free_data(data, true, INVALID_MAP, NULL);
				j++;
			}
		}
		else
			check_middle_lines(data, map, i);
		j = 0;
		i++;
	}
	if (!data->map.position)
		free_data(data, true, INVALID_MAP, NULL);
	return (0);
}

void	check_middle_lines(t_data *data, char **map, int i)
{
	int	j;

	j = 0;
	while (map[i] && map[i][j])
	{
		if (!ft_strchr(AUTHORIZED, map[i][j]))
			free_data(data, true, INVALID_MAP, NULL);
		check_duplicates(data, map[i][j], i, j);
		if (ft_strchr(CHARACTERS, map[i][j]))
		{
			if (j == 0)
				free_data(data, true, INVALID_MAP, NULL);
			if (ft_strchr(SPACES, map[i][j - 1]))
				free_data(data, true, INVALID_MAP, NULL);
			if (ft_strchr(SPACES, map[i][j + 1]) || map[i][j + 1] == '\n')
				free_data(data, true, INVALID_MAP, NULL);
			if (ft_strchr(SPACES, map[i - 1][j]))
				free_data(data, true, INVALID_MAP, NULL);
			if (ft_strchr(SPACES, map[i + 1][j]))
				free_data(data, true, INVALID_MAP, NULL);
		}
		j++;
	}
}

int	check_duplicates(t_data *data, char value, int i, int j)
{
	if ((value == 'N' || value == 'S' || value == 'W' || value == 'E') && \
	!data->map.position)
	{
		data->map.position = true;
		data->pos_y = (double)(i + 0.5);
		data->pos_x = (double)(j + 0.5);
		data->dir_y = 0.0;
		data->dir_x = 0.0;
		init_start_position(value, data);
	}
	else if ((value == 'N' || value == 'S' || value == 'W' || value == 'E') && \
	data->map.position)
		free_data(data, true, INVALID_MAP, NULL);
	return (0);
}

void	init_start_position(char value, t_data *data)
{
	if (value == 'N')
	{
		data->dir_y = -1.0;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (value == 'S')
	{
		data->dir_y = 1.0;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (value == 'W')
	{
		data->dir_x = -1.0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	else if (value == 'E')
	{
		data->dir_x = 1.0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
}
