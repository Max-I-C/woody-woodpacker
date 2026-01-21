/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:51:23 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:33:48 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_nod;

	n_list = 0;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		n_nod = ft_lstnew(lst->content);
		if (n_nod == NULL)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		n_nod->content = f(n_nod->content);
		ft_lstadd_back(&n_list, n_nod);
		lst = lst->next;
	}
	return (n_list);
}
