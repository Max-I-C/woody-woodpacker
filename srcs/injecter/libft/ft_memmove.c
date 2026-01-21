/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:05:24 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 19:53:19 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*check_dst;
	char	*check_src;
	size_t	count;

	count = 0;
	check_dst = ((char *)dst);
	check_src = ((char *)src);
	if (dst == NULL && src == NULL)
		return (dst);
	if (check_dst > check_src)
	{
		while (len-- > 0)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
	{
		while (count < len)
		{
			((unsigned char *)dst)[count] = ((unsigned char *)src)[count];
			count++;
		}
	}
	return (dst);
}

/*
int main(void)
{
    char c[8] = "aaaaaaa";
    char q[5] = "dddd";
   	ft_memmove(c, q, 3);
    printf("%s \n", c);
    return (0);
}
*/
