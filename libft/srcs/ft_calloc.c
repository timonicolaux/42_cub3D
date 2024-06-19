/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:49:16 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:36:47 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*zone;
	size_t		i;
	void		*zero_alloc;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		zero_alloc = malloc(0);
		if (!zero_alloc)
			return (NULL);
		return (zero_alloc);
	}
	if (__SIZE_MAX__ / nmemb < size)
		return (0);
	zone = (void *)malloc(nmemb * size);
	if (!zone)
		return (0);
	while (i < (nmemb * size))
	{
		*(unsigned char *)(zone + i) = 0;
		i++;
	}
	return (zone);
}
