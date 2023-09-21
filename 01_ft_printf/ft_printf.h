/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:04:18 by dphang            #+#    #+#             */
/*   Updated: 2023/09/21 17:40:47 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_checkformat(char format, char *str, int i)
{
	if (format == c)
		ft_putchar(str[i]);
	if (format == s)
		ft_putstr(s
	if (format == p)
		
	if (format == d)
		ft_putnbr
	if (format == i)
		ft_putnbr
	if (format == u)

	if (format == x)
	if (format == X)
	if (format == %)
		ft_putchar(str[i]);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i += ft_checkformat(str[i + 1], &str[i], i);
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	va_end(args);
}

int	main(int ac, char **av)
{
	return (0);
}
