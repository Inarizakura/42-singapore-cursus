/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 20:07:06 by dphang            #+#    #+#             */
/*   Updated: 2023/09/19 19:21:29 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcount(char const *s, int i, char c)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}

static int	ft_wordcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			i += ft_charcount(s, i, c);
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free(char **s, int i)
{
	while (i >= 0)
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
	int		words;
	char	**str;

	i = 0;
	j = 0;
	words = ft_wordcount(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!s || !str)
		return (NULL);
	while (j < words)
	{
		while (s[i] == c)
			i++;
		if (s[i])
			str[j] = ft_substr(s, i, ft_charcount(s, i, c));
		if (!str[j])
			return (ft_free(str, j));
		j++;
		i += ft_charcount(s, i, c);
	}
	str[j] = NULL;
	return (str);
}
