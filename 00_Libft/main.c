/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:35:05 by dphang            #+#    #+#             */
/*   Updated: 2023/09/06 17:42:26 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
//	int	n;
//	n = ft_atoi(av[3]);
	if (ac > 1)
	{
/*		printf("%s\n", av[1]);
		ft_memset(av[1], av[2][0], n);
		printf("%s\n", av[1]);
		ft_bzero(av[1], n);
		printf("%s\n", av[1]);*/
		printf("%s\n", av[1]);
		av[1] = ft_strchr(av[1], av[2][0]);
		printf("%s\n", av[1]);
	}
	return (0);
}
