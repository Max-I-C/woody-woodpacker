/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:08:38 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 21:36:24 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*suite_join(char const *s1, char const *s2,
						char *new_char, int len1)
{
	int	count;

	count = 0;
	if (s1 && s2)
	{
		while (s1[count] != '\0')
		{
			new_char[count] = s1[count];
			count++;
		}
		count = 0;
		while (s2[count] != '\0')
		{
			new_char[len1] = s2[count];
			count++;
			len1++;
		}
		new_char[len1] = '\0';
		return (new_char);
	}
	return (new_char);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*new_char;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_char = malloc((len1 + len2 + 1) * sizeof(char));
	if (new_char == NULL)
		return (NULL);
	suite_join(s1, s2, new_char, len1);
	return (new_char);
}
/*
int main(void)
{
	const char *str1 = "Bonjour ";
	const char *str2 = "Tranquille ? ";
	char *new_char = ft_strjoin(str1, str2);
	printf("%s\n", new_char);
}
*/
