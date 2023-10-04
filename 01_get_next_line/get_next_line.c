/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:05 by dphang            #+#    #+#             */
/*   Updated: 2023/10/04 17:07:32 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	checknl(char *storage)
{
	size_t	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static char	*cleanstorage(char *storage, size_t size)
{
	char	*temp;
	size_t	nl;

	nl = checknl(storage);
	temp = ft_substr(storage, nl, (size - nl), size);
	free(storage);
	storage = ft_strdup(temp, (size - nl));
	free(temp);
	return (storage);
}

static char	*readline(int fd, char *storage, char *temp, size_t size)
{
	storage = ft_calloc((size + 1), sizeof(char));
	if (!storage)
		return (NULL);
	while (!checknl(storage))
	{
		temp = 
		read(fd, storage, size);
		storage[size] = '\0';
	}
	storage = cleanstorage(storage, size);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage;
	char			*temp;
	char			*res;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);

	res = readline(fd, storage, temp, BUFFER_SIZE);
	return(res);
}
