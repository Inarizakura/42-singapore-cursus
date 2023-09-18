/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dphang <dphang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:38:27 by dphang            #+#    #+#             */
/*   Updated: 2023/09/19 00:30:58 by dphang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_lst;
	t_list	*node;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	res_lst = NULL;
	while (lst)
	{
		temp = f(lst->content);
		node = ft_lstnew(temp);
		if (!node)
		{
			if (temp)
				del(temp);
			ft_lstclear(&res_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&res_lst, node);
		lst = lst->next;
	}
	return (res_lst);
}
