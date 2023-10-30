/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:24:41 by dphang            #+#    #+#             */
/*   Updated: 2023/10/30 10:14:04 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This project is about handling pipes.

	Makefile:
		NAME	all	clean	fclean	re
	
	ARGUMENTS:
		file1 cmd1 cmd2 file2

	ALLOWED FUNCTIONS:
		open	close	read	write	malloc	free
		perror	strerror		access	dup		dup2
		execve	exit	fork	pipe	unlink	wait
		waitpid

		ft_printf and any equivalent you coded
		libft authorized
*/

#include "pipex.h"

void	pipex();

int	main(int ac, char **av)
{
	if (ac == 5)
		pipex();
	return (0);
}
