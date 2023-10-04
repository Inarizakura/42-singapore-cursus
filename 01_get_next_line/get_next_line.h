/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:53 by dphang            #+#    #+#             */
/*   Updated: 2023/10/04 17:07:29 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*s_buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);	
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char const *str);
char	*ft_substr(char const *s, size_t start, size_t len, size_t s_len);
#endif
