/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:42:08 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:32:37 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (temp -> next != NULL)
		temp = temp -> next;
	temp -> next = new;
}

/*
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
	
    t_list *new_element = ft_lstnew("resultat : 5");
    if (!new_element)
        return 0;
    ft_lstadd_back(&lst, new_element);

    t_list *current = lst;
    while (current)
    {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    return 0;
}
*/
