/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:35:05 by dphang            #+#    #+#             */
/*   Updated: 2023/09/09 11:38:40 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

int	main(int ac, char **av)
{
//	int	n;
//	n = ft_atoi(av[3]);
	if (ac > 1)
	{
		printf("%s\n", av[1]);
		ft_memset(av[1], av[2][0], n);
		printf("%s\n", av[1]);
		ft_bzero(av[1], n);
		printf("%s\n", av[1]);
		printf("%s\n", av[1]);
		av[1] = ft_strchr(av[1], av[2][0]);
		printf("%s\n", av[1]);
	}
	return (0);
}*/

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	n = atoi(av[3]);
	char	*s;

	if (ac == 4)
	{
		printf("%s\n", av[1]);
		s = ft_strnstr(av[1], av[2], n);
		printf("%s\n", s);
	}
	return (0);
}


