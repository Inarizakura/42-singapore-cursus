/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:04:18 by dphang            #+#    #+#             */
/*   Updated: 2023/10/02 12:57:28 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_checkformat(va_list args, char format, int *count)
{
	if (format == 'c')
		ft_putchar(va_arg(args, unsigned int), count);
	if (format == 's')
		ft_putstr(va_arg(args, char *), count);
	if (format == 'p')
		ft_putptr(va_arg(args, void *), count);
	if (format == 'd')
		ft_tounsigned(va_arg(args, int), "0123456789", count);
	if (format == 'i')
		ft_tounsigned(va_arg(args, int), "0123456789", count);
	if (format == 'u')
		ft_putullnbr(va_arg(args, unsigned int), "0123456789", count);
	if (format == 'x')
		ft_putullnbr(va_arg(args, unsigned int), "0123456789abcdef", count);
	if (format == 'X')
		ft_putullnbr(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	if (format == '%')
		ft_putchar('%', count);
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
			ft_checkformat(args, str[i + 1], &count);
			i++;
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
