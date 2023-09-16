/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:09:55 by dphang            #+#    #+#             */
/*   Updated: 2023/09/16 19:36:44 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digit_count(long int num)
{
	if (num / 10 != 0)
		return (1 + digit_count(num / 10));
	if (num < 0)
		return (2);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	int			i;
	int			d;
	long int	num;
	char		*str;

	num = n;
	d = digit_count(num);
	str = (char *)malloc((d + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	i = (d - 1);
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (num % 10) + 48;
		num /= 10;
		i--;
	}
	str[d] = '\0';
	return (str);
}
