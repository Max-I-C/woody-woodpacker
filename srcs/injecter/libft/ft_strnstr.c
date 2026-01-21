/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 21:36:21 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 20:20:05 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	c_s;
	size_t	c_f;	
	size_t	len_find;
	char	*new_c;

	c_s = 0;
	new_c = (char *)str;
	len_find = ft_strlen(to_find);
	if (len_find == 0 || str == to_find)
		return (new_c);
	while (new_c[c_s] != '\0' && c_s < len)
	{
		c_f = 0;
		while (new_c[c_s + c_f] != '\0' && to_find[c_f] != '\0'
			&& c_s + c_f < len && new_c[c_s + c_f] == to_find[c_f])
			c_f++;
		if (c_f == len_find)
			return (new_c + c_s);
		c_s++;
	}
	return (0);
}
/*
int		main(void)
{
	char	*str;
	char	*to_find;

	str = "Bonjour";
	to_find = "jour";
	printf("%s\n", ft_strnstr(str, to_find, 10));
	printf("%s\n", strnstr(str, to_find, 10));
}
*/
