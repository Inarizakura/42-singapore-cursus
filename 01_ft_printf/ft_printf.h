/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:08:48 by dphang            #+#    #+#             */
/*   Updated: 2023/09/28 14:22:56 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_strlen(char *str);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putullnbr_base(unsigned long long int nbr, char *base, int *count);
void	ft_putptr(void *ptr, int *count);

#endif
