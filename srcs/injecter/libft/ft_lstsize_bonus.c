/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:47:53 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/20 15:34:14 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
t_list *create_lst(t_list *lst)
{
	int count = 0;

	while(count < 10)
	{
		t_list *new;
		new = malloc(sizeof(t_list));
		if (new == NULL)
			return NULL;
		new->content = malloc(sizeof(char) * 15);
		if (new->content == NULL)
			return NULL;
		new->content = "Liste test";
		ft_lstadd_back(&lst, new);
		count++;
	}
	return(lst);
}
*/

/*
int main(void)
{
	t_list *lst; 

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return 0;
	lst->content = "resultat : 13";
	lst->next = NULL;
	create_lst(lst);
	printf("%d\n", ft_lstsize(lst)); 
	printf("%s\n", lst->content); 
}
*/
