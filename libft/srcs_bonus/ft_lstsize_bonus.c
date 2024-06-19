/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:07:23 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:38:17 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t		size;
	t_list		*actual;

	size = 0;
	actual = lst;
	while (actual != NULL)
	{
		size++;
		actual = actual->next;
	}
	return (size);
}
