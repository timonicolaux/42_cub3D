/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:52:46 by nsouchal          #+#    #+#             */
/*   Updated: 2024/05/24 08:38:12 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_struct;
	t_list	*new_lst;
	void	*temp;

	if (!f || !del || !lst)
		return (0);
	new_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		new_struct = ft_lstnew(temp);
		if (!new_struct)
		{
			ft_lstclear(&new_lst, del);
			free(temp);
		}
		else
		{
			ft_lstadd_back(&new_lst, new_struct);
			lst = lst->next;
		}
	}
	return (new_lst);
}
