/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:00:17 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:37:45 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_litl;

	i_big = 0;
	i_litl = 0;
	if (little[i_litl] == '\0')
		return ((char *)big);
	while (i_big < len && big[i_big])
	{
		while ((big[i_big] == little[i_litl]) && i_big < len && little[i_litl])
		{
			i_big++;
			i_litl++;
			if (little[i_litl] == '\0')
				return (((char *)big) + (i_big - i_litl));
		}
		i_big = i_big - i_litl + 1;
		i_litl = 0;
	}
	return (0);
}
