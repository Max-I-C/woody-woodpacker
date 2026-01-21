/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:14:49 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:33:13 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!(lst) || !(del))
		return ;
	del(lst->content);
	free(lst);
	lst = NULL;
}

/*
static void free_content(void *content)
{
    free(content);
}

int main(void)
{
	t_list *lst = ft_lstnew("resultat : 1");
    t_list *lst2 = ft_lstnew("resultat : 2");
    t_list *lst3 = ft_lstnew("resultat : 3");
    t_list *lst4 = ft_lstnew("resultat : 4");

    if (!lst || !lst2 || !lst3 || !lst4)
        return 0;

    lst->next = lst2;
    lst2->next = lst3;
    lst3->next = lst4;

	ft_lstdelone(lst4, &free_content);
    return 0;
}
*/
