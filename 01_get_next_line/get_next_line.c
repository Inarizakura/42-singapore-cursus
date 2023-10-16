/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:05 by dphang            #+#    #+#             */
/*   Updated: 2023/10/16 14:03:40 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	resetstorage(char **storage)
{
	free(*storage);
	*storage = NULL;
}

static void	storeline(char **storage, char *temp)
{
	char	*hold;

	if (!*storage)
		*storage = gnl_strdup(temp);
	else
	{
		hold = gnl_strjoin(*storage, temp);
		free(*storage);
		*storage = gnl_strdup(hold);
		free(hold);
	}
}

static int	readline(int fd, char **storage)
{
	char	*temp;
	int		is_read;

	temp = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!temp)
		return (0);
	is_read = 1;
	while (is_read > 0)
	{
		is_read = read(fd, temp, BUFFER_SIZE);
		if (is_read == 0)
			break ;
		else if (is_read < 1)
		{
			resetstorage(storage);
			free(temp);
			return (0);
		}
		temp[is_read] = '\0';
		storeline(storage, temp);
		if (checknl(*storage))
			break ;
	}
	free(temp);
	return (1);
}

static char	*procline(char **storage)
{
	char	*res;
	char	*hold;
	size_t	nl;
	size_t	len;

	nl = 0;
	len = 0;
	while (storage[0][nl] && storage[0][nl] != '\n')
		nl++;
	while (storage[0][len])
		len++;
	hold = gnl_strdup(*storage);
	free(*storage);
	*storage = gnl_substr(hold, nl + 1, len);
	res = gnl_substr(hold, 0, nl + 1);
	free(hold);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*res;
	int			valid_read;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	valid_read = readline(fd, &storage);
	if (!storage)
		return (NULL);
	if (valid_read)
		res = procline(&storage);
	if (!res || !*res)
	{
		resetstorage(&storage);
		free(res);
		return (NULL);
	}
	return (res);
}
