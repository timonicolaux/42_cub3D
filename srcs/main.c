/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouchal <nsouchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:19:27 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/29 09:11:46 by nsouchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (!check_file_extension(argv[1]))
		{
			init_data(&data);
			parse_file(argv[1], &data);
			init_mlx(&data);
			raycasting(&data);
			mlx_loop(data.mlx_ptr);
		}
	}
	else
		ft_printf("Please include one .cub file\n");
	return (0);
}
