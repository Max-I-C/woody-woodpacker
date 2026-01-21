/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:43:33 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 21:26:34 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int nb, int check)
{
	int	count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	if (check == 1)
		count++;
	return (count);
}

static char	*allocation(char *new_char, int n, int len_new)
{
	new_char[len_new] = '\0';
	while (len_new-- > 0)
	{
		new_char[len_new] = n % 10 + '0';
		n = n / 10;
	}
	return (new_char);
}

char	*ft_itoa(int n)
{
	int		len_new;
	int		check;
	char	*new_char;

	check = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		check = 1;
	}
	len_new = count_len(n, check);
	new_char = malloc((len_new + 1) * sizeof(char));
	if (new_char == NULL)
		return (NULL);
	new_char = allocation(new_char, n, len_new);
	if (check == 1)
		new_char[0] = '-';
	return (new_char);
}
/*
int main ()
{
	char *result = ft_itoa(-12545);
	printf("%s\n", result);
}
*/
