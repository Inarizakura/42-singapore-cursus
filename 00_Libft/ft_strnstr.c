/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:22:45 by dphang            #+#    #+#             */
/*   Updated: 2023/09/07 15:56:38 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (needle[len])
		len++;
	if (needle[i] == '\0')
		return ((char *)haystack);
	if (len < n)
	{
		while (haystack[i] && i + len < n)
		{
			j = 0;
			while (haystack[i + j] == needle[j]	&& haystack[i + len] != '\0'
				&& needle[j] != '\0')
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i + j]);
			i++;
		}
	}
	return (0);
}
