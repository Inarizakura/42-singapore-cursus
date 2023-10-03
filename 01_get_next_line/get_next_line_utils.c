/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:44 by dphang            #+#    #+#             */
/*   Updated: 2023/10/03 17:00:35 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(size_t size)
{
	t_list	*node;

	node = malloc(sizeof(t_list) + 1);
	if (!node)
		return (NULL);
	node->s_buffer = read(fd, ,BUFFER_SIZE);
	node->s_buffer[BUFFER_SIZE] = '\0';
	node->next = NULL;
	return (node);
}

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
