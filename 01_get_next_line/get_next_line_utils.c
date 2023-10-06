/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:44 by dphang            #+#    #+#             */
/*   Updated: 2023/10/06 15:59:04 by dphang           ###   ########.fr       */
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
	while (i < size)
	{
		t_ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*res;

	len = 0;
	while (s1[len])
		len++;
	res = gnl_calloc((len + BUFFER_SIZE + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	return (res);
}

char	*gnl_strdup(const char *str)
{
	int		len;
	int		i;
	char	*res;

    len = 0;
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
	return (res);
}

/*char	*ft_substr(char const *s, size_t start, size_t len, size_t s_len)
{
	size_t	i;
	char	*res;

	if (start > s_len)
		return (ft_strdup("", 1));
	if ((start + len) > s_len)
		res = ft_calloc((s_len - start + 1), sizeof(char));
	else
		res = ft_calloc((len + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && start < s_len && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}*/
