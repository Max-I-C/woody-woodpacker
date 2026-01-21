/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:49:41 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 19:34:48 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	count;

	count = 0;
	while (count != n)
	{
		((unsigned char *)s)[count] = 0;
		count++;
	}
}
/*
int main(void)
{
	char c[5] = "AAAA";
	char d[5]  = "AAAA";
	ft_bzero(c, 2);
	bzero(d, 2);	
	printf("%s\n", c);
	printf("%s\n", d);
	return(0);
}
*/
