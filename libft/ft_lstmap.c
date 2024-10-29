/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:24:31 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/17 10:26:38 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nxt;
	t_list	*now;

	nxt = NULL;
	while (lst)
	{
		now = ft_lstnew((*f)(lst -> content));
		if (!now)
		{
			ft_lstclear(&nxt, del);
			return (NULL);
		}
		ft_lstadd_back(&nxt, now);
		lst = lst -> next;
	}
	return (nxt);
}
