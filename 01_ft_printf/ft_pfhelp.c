/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfhelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:53:35 by dphang            #+#    #+#             */
/*   Updated: 2023/09/23 18:53:32 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i += write(1, &s[i], 1);
	return (i);
}

int	ft_putnbrbase(int nbr)
{
	int			count;
	long int	nb;

	count = 0;
	nb = nbr;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
		count++;
	}
	if (nbr > 9)
		ft_putnbrbase(nbr / 10);
	if (nbr >= 0)
		count += ft_putchar((nbr % 10) + '0');
	return (count);
}
