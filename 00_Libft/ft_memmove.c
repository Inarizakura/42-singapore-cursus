/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:09:57 by dphang            #+#    #+#             */
/*   Updated: 2023/09/15 19:59:47 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = n - 1;
	d = (char *)dest;
	s = (char *)src;
	if (!d && !s)
		return (((void *)0));
	if (&d[i] < &s[i])
		ft_memcpy(d, s, n);
	else
	{
		while ((i + 1) > 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}
