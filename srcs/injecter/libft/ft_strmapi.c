/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:27:03 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 21:28:14 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static char ft_exemple(unsigned int nb_t, char ch_t)
{
	if (nb_t > 1)
		ch_t = '+';
	return(ch_t);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*new_char;

	count = 0;
	new_char = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (new_char == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		new_char[count] = f(count, s[count]);
		count++;
	}
	new_char[count] = '\0';
	return (new_char);
}
/*
int main(void)
{
	char *result = ft_strmapi("Bonjour", ft_exemple);
	printf("%s\n", result);
}
*/
