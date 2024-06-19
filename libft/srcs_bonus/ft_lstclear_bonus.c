/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:10:48 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:38:02 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actual;
	t_list	*next_elem;

	if (!del || !lst)
		return ;
	actual = *lst;
	while (actual)
	{
		next_elem = actual->next;
		ft_lstdelone(actual, del);
		actual = next_elem;
	}
	*lst = NULL;
}
