/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:05 by dphang            #+#    #+#             */
/*   Updated: 2023/10/10 18:15:05 by dphang           ###   ########.fr       */
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

static char	*holdstr(char *storage, char *hold)
{
	char	*temp;

	if (!hold)
		hold = gnl_strdup(storage);
	else
	{
		temp = gnl_strdup(hold);
		free(hold);
		hold = gnl_strjoin(temp, storage);
		free(temp);
	}
	return (hold);
}

static char	*readline(int fd, char *storage, char *hold)
{
	if (!storage)
		storage = gnl_calloc(BUFFER_SIZE, sizeof(char));
	while (!checknl(storage))
	{
		read(fd, storage, BUFFER_SIZE);
		hold = holdstr(storage, hold);
	}
	return (hold);
}

static char	*procline(char *storage, char *hold)
{
	char	*res;
	char	*temp;
    size_t	nl;
    size_t	len;

	if (storage)
		temp = holdstr(storage, hold);
	free(hold);
	free(storage);
	while (temp[nl] && temp[nl] != '\n')
		nl++;
	while (temp[len])
		len++;
	storage = gnl_substr(temp, nl, len, len);
	res = gnl_substr(temp, 0, nl, len);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*hold;
	char		*res;

	hold = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	readline(fd, storage, hold);
	res = procline(storage, hold);
//	if (!res)
//		return (NULL);;
	return (res);
}
