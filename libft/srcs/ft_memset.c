/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:36:19 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:37:08 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;
	size_t			i;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = c;
		i++;
	}
	return (buffer);
}
