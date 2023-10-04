/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:44 by dphang            #+#    #+#             */
/*   Updated: 2023/10/04 17:06:07 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*t_list	*ft_lstnew(size_t size)
{
	t_list	*node;

	node = malloc(sizeof(t_list) + 1);
	if (!node)
		return (NULL);
	node->s_buffer = read(fd, ,BUFFER_SIZE);
	node->s_buffer[BUFFER_SIZE] = '\0';
	node->next = NULL;
	return (node);
}*/

void	*ft_calloc(size_t nmemb, size_t size)
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

char	*ft_strjoin(char const *s1, char const *s2, size_t size)
{
	size_t	s1_len;
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	s1_len = 0;
	while (s1[s1_len])
		s1_len++;
	res = calloc((s1_len + size), sizeof(char));
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	return (res);
}

char	*ft_strdup(char const *s, size_t size)
{
	int		i;
	char	*res;

	res = ft_calloc((size + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_substr(char const *s, size_t start, size_t len, size_t s_len)
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
}
/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	size_t	n = 5;
	char	*str1 = ft_calloc(5, sizeof(char));
	char	*str2 = calloc(5, sizeof(char));
	printf("%d\n", strncmp(str1, str2, n));
	if (strncmp(str1, str2, n) == 0)
		printf("Calloc-ed Successfully");
	else
		printf("Calloc Failed");
	free(str1);
	free(str2);
	return 0;
}*/
