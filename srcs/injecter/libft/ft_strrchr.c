/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:50:50 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 20:22:31 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*new_char;

	new_char = (char *)s;
	count = ft_strlen(s);
	while (count >= 0)
	{
		if (new_char[count] == (char)c)
			return (&new_char[count]);
		count--;
	}
	return (NULL);
}
/*
int main(void)
{
	const char str1[] = "bonjour";
	const char st1[] = "bonjour";
	char str2 = *ft_strrchr(str1, 'j');
	char st2 = *strrchr(st1, 'j');
	printf("%c\n", str2);
	printf("%c\n", st2);
}
*/
