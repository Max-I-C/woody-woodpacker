/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:52:56 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:33:39 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != (NULL))
		lst = lst -> next;
	return (lst);
}
/*
int main(void)
{
	t_list *lst = malloc(sizeof(t_list));
	t_list *lst2 = malloc(sizeof(t_list));
	t_list *lst3 = malloc(sizeof(t_list));
	t_list *lst4 = malloc(sizeof(t_list));

	if (!lst || !lst2 || !lst3 || !lst4)
		return 0;
		
	lst->content = "resultat : 1";
	lst->next = lst2;
	lst2->content = "resultat : 2";
	lst2->next = lst3;
	lst3->content = "resultat : 3";
	lst3->next = lst4;
	lst4->content = "resultat : 4";
	lst4->next = NULL;
	t_list *test = ft_lstlast(lst);
	
	printf("%s\n", lst->content);
	printf("%s\n", lst2->content);
	printf("%s\n", lst3->content);
	printf("%s\n", lst4->content);
	printf("%s\n", test->content);
}
*/
