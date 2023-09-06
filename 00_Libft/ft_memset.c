/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:24:11 by dphang            #+#    #+#             */
/*   Updated: 2023/09/06 13:21:34 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*str;
	char		ch;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	while (i < n)
	{
		str[i] = ch;
		i++;
	}
	return (s);
}
