/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:22:43 by nsouchal          #+#    #+#             */
/*   Updated: 2024/06/10 14:51:10 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color_str(t_data *data, char *texture, char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (texture[i])
	{
		if (texture[i] != ',' && !ft_isdigit(texture[i]) && \
		!ft_strchr(SPACES, texture[i]))
		{
			free(texture);
			free_data(data, true, INVALID_CUB_FILE, line);
		}
		if (texture[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
	{
		free(texture);
		free_data(data, true, INVALID_CUB_FILE, line);
	}
	return (0);
}

int	check_rgb_value(int value)
{
	if (value < 0 || value > 255)
		return (1);
	return (0);
}

void	check_space_in_color(t_data *data, char *line, int i)
{
	int	counter;

	counter = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_isdigit(line[i]))
			counter++;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		if (!line[i] || line[i] == '\n')
			break ;
		if (!ft_isdigit(line[i]) && line[i] != ',' && \
		!ft_strchr(SPACES, line[i]))
			free_data(data, true, INVALID_CUB_FILE, line);
		while (line[i] && (ft_strchr(SPACES, line[i]) || line[i] == ','))
			i++;
	}
	if (counter != 3)
		free_data(data, true, INVALID_CUB_FILE, line);
}

int	parse_color(int i, char *line, t_data *data, char *name_tex)
{
	int		j;
	int		length;
	char	*texture;

	j = 0;
	length = 0;
	if (!ft_strchr(SPACES, line[i]))
		free_data(data, true, INVALID_CUB_FILE, line);
	check_space_in_color(data, line, i);
	while (line[i])
	{
		i++;
		length++;
	}
	texture = malloc((length + 1) * sizeof(char));
	if (!texture)
		free_data(data, true, MALLOC_ERROR, line);
	i -= length;
	while (line[i] && line[i] != '\n')
		texture[j++] = line[i++];
	texture[j] = '\0';
	store_texture(texture, data, name_tex, line);
	return (0);
}

int	find_zero(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(SPACES, str[i]))
			i++;
		if (str[i] != '0')
			return (1);
		if (str[i] == '0' && ft_isdigit(str[i + 1]))
			return (2);
		if (ft_strchr(SPACES, str[i + 1]))
			return (0);
		i++;
	}
	return (0);
}
