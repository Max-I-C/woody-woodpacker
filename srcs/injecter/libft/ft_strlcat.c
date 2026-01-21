/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:11:59 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 20:08:17 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	size_t	i;
	size_t	l_dest;
	size_t	l_src;
	size_t	total;

	i = 0;
	total = 0;
	s = (char *)src;
	l_dest = ft_strlen(dst);
	l_src = ft_strlen(s);
	if (l_dest < dstsize)
		total = l_src + l_dest;
	else
		total = l_src + dstsize;
	while (s[i] && (l_dest + 1) < dstsize)
	{
		dst[l_dest] = s[i];
		l_dest++;
		i++;
	}
	dst[l_dest] = '\0';
	return (total);
}

/*
int main(void)
{
	char src1[] = "pqrstuvwxyz";
	char dst1[30] = "abcd";
	char src[] = "pqrstuvwxyz";
	char dst[30] = "abcd";
	int reuslt = ft_strlcat(dst, src, 13);
	int result2 = strlcat(dst1, src1, 13); 

	ft_strlcat(dst, src, 1);
	strlcat(dst1, src1, 1); 
	printf("%s\n", dst);
	printf("%s\n", dst1);
	printf("%d\n", reuslt);
	printf("%d\n", result2);
}
*/
