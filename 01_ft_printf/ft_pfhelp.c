/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfhelp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:53:35 by dphang            #+#    #+#             */
/*   Updated: 2023/10/02 12:57:39 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putptr(void *ptr, int *count)
{
	if (!ptr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_putullnbr((unsigned long long int)ptr, "0123456789abcdef", count);
}

void	ft_tounsigned(int nbr, char *base, int *count)
{
	long long int	nb;

	nb = nbr;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= -1;
	}
	ft_putullnbr(nb, base, count);
}

void	ft_putullnbr(unsigned long long int nbr, char *base, int *count)
{
	int	b_len;

	b_len = 0;
	while (base[b_len])
		b_len++;
	if (b_len == 10)
	{
		if (nbr > 9)
			ft_putullnbr((nbr / 10), base, count);
		ft_putchar(base[nbr % 10], count);
	}
	else if (b_len == 16)
	{
		if (nbr > 15)
			ft_putullnbr((nbr / 16), base, count);
		ft_putchar(base[nbr % 16], count);
	}
}
