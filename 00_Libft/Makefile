# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dphang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 11:30:51 by dphang            #+#    #+#              #
#    Updated: 2023/09/09 17:03:54 by dphang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_isdigit.c ft_strdup.c ft_toupper.c ft_ascii.c ft_isprint.c ft_strlen.c ft_atoi.c ft_memcpy.c ft_strncmp.c libft.h.gch ft_bzero.c ft_memmove.c ft_strnstr.c ft_isalnum.c ft_memset.c ft_strrchr.c ft_isalpha.c ft_strchr.c ft_tolower.c
OBJS=$(SRCS:.c=.o)
NAME=libft.a

$(NAME):
	ar rc $(NAME)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
