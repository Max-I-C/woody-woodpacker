/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaac-c <misaac-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:58:23 by misaac-c          #+#    #+#             */
/*   Updated: 2024/02/13 14:52:35 by misaac-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static void	free_memory(char **split, int j)
{
	while (--j >= 0)
		free(split[j]);
	free(split);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	word;
	int	check;

	count = 0;
	check = 0;
	word = 0;
	while (s[count] != '\0')
	{
		if (s[count] != c && check == 0)
		{
			check = 1;
			word++;
		}
		else if (s[count] == c)
			check = 0;
		count++;
	}
	return (word);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			if (!split[j - 1])
				return (free_memory(split, j), NULL);
			index = -1;
		}
	}
	split[j] = NULL;
	return (split);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main(void)
{
    const char *str = "Bonjour,comment,ca,va ?";
    char **result = ft_split(str, ',');
    
    if (result == NULL) 
	{
        printf("Erreur");
        return 1;
    }

    // -- Affichage des mots découpés -- //
    int i = 0;
    while (result[i] != NULL) 
	{
        printf("Mot %d : %s\n", i + 1, result[i]);
        i++;
    }

    // -- Libération de la mémoire allouée --//
    int j = 0;
    while (result[j] != NULL) 
	{
        free(result[j]);
        j++;
    }
    free(result);
}
*/
