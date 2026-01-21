/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:54:53 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 19:50:14 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*st1;
	unsigned char	*st2;

	count = 0;
	st1 = ((unsigned char *)s1);
	st2 = ((unsigned char *)s2);
	while (n--)
	{
		if (st1[count] != st2[count])
			return (st1[count] - st2[count]);
		count++;
	}
	return (0);
}
/*
int main(void)
{
	char str1[] = "Bonjour";
	char str2[] = "jour";

	char st1[] = "Bonjour";
	char st2[] = "jour";

	int result = ft_memcmp(str1, str2, 50);
	int result2 = memcmp(st1, st2, 50);
	printf("%d\n", result);
	printf("%d\n", result2);

}
*/
