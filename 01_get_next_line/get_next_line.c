/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:05 by dphang            #+#    #+#             */
/*   Updated: 2023/10/13 11:33:36 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	checknl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static void	readline(int fd, char **storage, char **hold)
{
	char	*temp;
	size_t	is_read;

	*storage = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	is_read = 1;
	while (is_read > 0)
	{
		if (!checknl(*storage))
			is_read = read(fd, *storage, BUFFER_SIZE);
		if (!*hold)
			*hold = gnl_strdup(*storage);
		else
		{
			temp = gnl_strjoin(*hold, *storage);
			free(*hold);
			*hold = gnl_strdup(temp);
			free(temp);
			if (checknl(*storage))
				return ;
		}
	}
}

static char	*procline(char **storage, char **hold)
{
	char	*res;
	size_t	nl;
	size_t	len;

	nl = 0;
	len = 0;
	while (hold[0][nl] && hold[0][nl] != '\n')
		nl++;
	while (hold[0][len])
		len++;
	free(*storage);
	*storage = gnl_substr(*hold, nl - 1, len + 1, len);
	res = gnl_substr(*hold, 0, nl + 1, len);
	free(*hold);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*hold;
	char		*res;

	storage = '\0';
	hold = '\0';
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	readline(fd, &storage, &hold);
	if (!storage || !hold)
		return (NULL);
	res = procline(&storage, &hold);
	if (!res)
		return (NULL);
	return (res);
}
