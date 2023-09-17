/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:07:06 by dphang            #+#    #+#             */
/*   Updated: 2023/09/17 23:25:05 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	word_count(char const *s, char c)
{
	int	i;
	int	is_word;
	int	words;

	i = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c && !is_word)
		{
			words++;
			is_word = 1;
		}
		if (s[i] == c && is_word)
			is_word = 0;
		i++;
	}
	return (words);
}

static int	char_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		is_word;
	int		words;
	char	**str;
	
	i = 0;
	is_word = 0;
	words = word_count(s, c);
	printf("%d\n", words);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!*str)
		return (NULL);
	while (s[i])
	{
		j = 0;
		if (s[i] != c && !is_word)
		{
			str[i] = (char *)malloc((char_count(s, c) + 1) * sizeof(char));
			if (!str[i])
				return (NULL);
			is_word = 1;
		}
		else if (s[i] == c && is_word)
			is_word = 0;
		while (s[i] && is_word)
		{
			str[i][j] = s[i];
			j++;
			i++;
		}
		str[i][j] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
