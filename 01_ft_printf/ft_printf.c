/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:04:18 by dphang            #+#    #+#             */
/*   Updated: 2023/09/22 15:56:31 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkformat(va_list args, char format)
{
	if (format == 'c')
		return ((int)ft_putchar(va_arg(args, int)));
/*	if (format == 's')
		return ((int)ft_putstr(va_arg(args, int)));*/
	if (format == 'p')
		return (0);
	if (format == 'd')
		return (0);
	if (format == 'i')
		return (0);
	if (format == 'u')
		return (0);
	if (format == 'x')
		return (0);
	if (format == 'X')
		return (0);
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
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
			count += ft_checkformat(args, str[i + 1]);
		else if (str[i - 1] != '%')
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

/*
int	main(int ac, char **av)
{
	return (0);
}*/
