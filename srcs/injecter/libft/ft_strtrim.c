/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:21:11 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 20:26:15 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	compare_set(char const src, char const *set)
{
	int	count;

	count = 0;
	while (set[count] != '\0')
	{
		if (src == set[count])
			return (1);
		count++;
	}
	return (0);
}

static char	*all_is_set(void)
{
	char	*new_char;

	new_char = malloc(sizeof(char));
	if (new_char == NULL)
		return (NULL);
	ft_strlcpy(new_char, "", 1);
	return (new_char);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len1;
	int		count;
	int		end;
	char	*new_char;

	count = 0;
	len1 = ft_strlen(s1);
	while (compare_set(s1[count], set))
		count++;
	if (count == len1)
		return (all_is_set());
	end = len1 - 1;
	while (compare_set(s1[end], set))
		end--;
	new_char = malloc((end - count + 2) * sizeof(char));
	if (new_char == NULL)
		return (NULL);
	ft_strlcpy(new_char, (s1 + count), (end - count + 2));
	return (new_char);
}
/*
int main(void)
{
	const char *str1 = "Bonjour";
	const char *str2 = "Bonjr";
	char *new_char = ft_strtrim(str1, str2);
	printf("%s\n", new_char);
}
*/
