/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:46:18 by tnicolau          #+#    #+#             */
/*   Updated: 2024/06/10 14:50:24 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	calc_map_num_lines(char *file, int *nb_lines, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_data(data, true, OPENING_FILE_ERROR, NULL);
	while (42)
	{
		line = get_next_line(fd, data);
		if (check_if_linemap(data, line, false))
			break ;
		free(line);
	}
	free(line);
	while (42)
	{
		line = get_next_line(fd, data);
		if (!line)
			break ;
		(*nb_lines)++;
		free(line);
	}
	*nb_lines += 1;
	close(fd);
	return (0);
}

int	fill_map_array(char **map, int fd, t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (42)
	{
		line = get_next_line(fd, data);
		if (check_if_linemap(data, line, false))
		{
			map[i++] = line;
			break ;
		}
		free(line);
	}
	while (42)
	{
		line = get_next_line(fd, data);
		if (!line)
			break ;
		if (!check_if_linemap(data, line, true))
			free_data(data, true, INVALID_MAP, NULL);
		map[i++] = line;
	}
	map[i] = NULL;
	return (0);
}

int	store_map(t_data *data, char *file)
{
	int		nb_lines;
	int		fd;
	int		i;

	nb_lines = 0;
	i = 0;
	calc_map_num_lines(file, &nb_lines, data);
	data->map.map = ft_calloc((nb_lines + 1), sizeof(char *));
	if (!data->map.map)
		free_data(data, true, MALLOC_ERROR, NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_data(data, true, OPENING_FILE_ERROR, NULL);
	fill_map_array(data->map.map, fd, data);
	map_checker(data, data->map.map, nb_lines);
	return (0);
}

int	check_if_linemap(t_data *data, char *line, bool free_line)
{
	int	i;

	i = 0;
	if (!line)
		free_data(data, true, INVALID_MAP, NULL);
	while (line[i] && ft_strchr(SPACES, line[i]))
		i++;
	if (line[i] == '1')
		return (1);
	if (free_line)
		free(line);
	return (0);
}
