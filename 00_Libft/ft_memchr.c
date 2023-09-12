/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 03:23:19 by dphang            #+#    #+#             */
/*   Updated: 2023/09/08 04:37:11 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (((void *)0));
}

/*#include <stdio.h>

int	main(void)
{
	char str[50] = "hello";
	char *res;
	int	c = 'l';

	printf("%s\n", str);
	res = (char *)memchr(str, c, 4);
	printf("%s\n", res);
	return (0);
}*/
