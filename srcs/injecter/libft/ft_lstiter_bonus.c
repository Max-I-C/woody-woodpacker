/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:45:48 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:33:23 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
static void ft_exemple(void *str)
{
	printf("fonction exemple\n");
	printf("%s\n", (char *)str);
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
	
	ft_lstiter(lst, &ft_exemple);
    return 0;
}
*/
