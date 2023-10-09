/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:05 by dphang            #+#    #+#             */
/*   Updated: 2023/10/09 18:01:27 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static int	checknl(char *storage)
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

static char	*clean_storage(char *storage, size_t size)
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
	char	*hold;
	char	*temp;

	hold = 0;
	temp = 0;
	storage = ft_calloc((size + 1), sizeof(char));
	if (!storage)
		return (NULL);
	while (!checknl(storage))
	{
		if (storage)
		{
			hold = ft_strjoin(temp, storage, size);
			free(temp);
			temp = ft_strdup(hold, size);
			free(storage);
		}
		read(fd, storage, size);
	}
	free(temp);
	storage = clean_storage(storage, size);
	return (hold);
}

char	*get_next_line(int fd)
{
	static char		*storage;
//	char			*temp;
	char			*res;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);

	res = readline(fd, storage, temp, BUFFER_SIZE);
	return(res);
}*/

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

static char *holdstr(char *hold, char *storage)
{
    char    *temp;

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
//	char	*temp;

//	temp = 0;
	if (!storage)
		storage = gnl_calloc(BUFFER_SIZE, sizeof(char));
	while (!checknl(storage))
	{
		read(fd, storage, BUFFER_SIZE);
     //   if (!checknl(storage))
        hold = holdstr(hold, storage);
	}
	return (hold);
}

static char procline(char *storage, char *hold)
{
    char    *str;
    char    *temp;
    //to-do:    replace storage from (\n + 1) to \0 and,
    //          store str up til \n.
    str = gnl_strdup(hold, start, stop)
    return (str);
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
