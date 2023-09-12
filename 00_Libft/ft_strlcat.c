/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:36:03 by dphang            #+#    #+#             */
/*   Updated: 2023/09/12 17:54:30 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (dst[len])
		len++;
	if ((size - len - 1) > 0 && src[i])
	{
		while (src[i] && (len + i) < size)
		{
			dst[len + i] = src[i];
			i++;
		}
		while (src[len])
			len++;
		dst[len + i] = '\0';
	}
	return (len);
}
