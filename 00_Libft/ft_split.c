/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:07:06 by dphang            #+#    #+#             */
/*   Updated: 2023/09/18 14:43:03 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	is_word;
	int	count;

	i = 0;
	is_word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && !is_word)
		{
			count++;
			is_word = 1;
		}
		if (s[i] == c && is_word)
			is_word = 0;
		i++;
	}
	return (count);
}

static int	ft_charcount(char const *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static char	**ft_free(char **s, size_t i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		is_word;
	char	**str;

	i = 0;
	j = 0;
	is_word = 0;
	str = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (s[i])
	{
		if (!is_word && s[i] != c)
		{
			str[j] = ft_substr(s, i, (ft_charcount(s, i, c)));
			if (!str[j])
				return (ft_free(str, (j + 1)));
			is_word = 1;
			j++;
		}
		else if (is_word && s[i] == c)
			is_word = 0;
		i++;
	}
	str[j] = '\0';
	return (str);
}
