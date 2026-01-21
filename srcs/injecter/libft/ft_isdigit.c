/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:27:30 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 19:31:25 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int dig)
{
	if ((dig >= 48) && (dig <= 57))
	{
		return (dig);
	}
	else
	{
		return (0);
	}
}
/*
int main (void)
{
	int result; 
	result = ft_isdigit('\001');
	printf("%d\n", result);
}
*/
