/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:35:07 by misaac-c          #+#    #+#             */
/*   Updated: 2024/01/30 19:26:15 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int alp)
{
	if (((alp > 64) && (alp < 91)) || ((alp > 96) && (alp < 123)))
	{
		return (alp);
	}
	else
	{
		return (0);
	}
}

/*
int main(void)
{
	int alp;
	int result; 
	alp = 'Q';
	result = ft_isalpha(alp);
	printf("%d\n", result);

}
*/
