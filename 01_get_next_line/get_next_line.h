/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:53 by dphang            #+#    #+#             */
/*   Updated: 2023/10/16 12:52:16 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*gnl_calloc(size_t nmemb, size_t size);	
char	*gnl_strjoin(const char *s1, char const *s2);
char	*gnl_strdup(char const *str);
char	*gnl_substr(char const *str, size_t start, size_t len);
size_t	checknl(char *str);
#endif
