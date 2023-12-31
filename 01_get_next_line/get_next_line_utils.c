/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:44 by dphang            #+#    #+#             */
/*   Updated: 2023/10/16 13:29:35 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*ptr;
	char	*t_ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	t_ptr = (char *)ptr;
	while (i < (nmemb * size))
	{
		t_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

size_t	checknl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*res;

	len = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[len])
		len++;
	res = gnl_calloc((len + BUFFER_SIZE + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

char	*gnl_strdup(const char *str)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	if (!str)
		return (gnl_strdup(""));
	while (str[len])
		len++;
	res = gnl_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*gnl_substr(char const *str, size_t start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*res;

	s_len = 0;
	while (str[s_len])
		s_len++;
	if (start > s_len)
		return (gnl_strdup(""));
	res = gnl_calloc((len - start + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (str[start + i] && (start + i) < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
