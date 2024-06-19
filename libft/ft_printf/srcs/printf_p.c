/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:27:05 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:49:05 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	printf_p(long unsigned int ptr)
{
	int	result;
	int	x;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	x = 'x';
	printf_s("0x");
	result = printf_xlow_xupp(ptr, x);
	return (result + 2);
}
