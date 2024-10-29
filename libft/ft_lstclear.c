/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:08:31 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/16 17:01:59 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nxt;
	t_list	*now;

	if (lst == NULL || del == NULL)
		return ;
	now = *lst;
	while (now)
	{
		nxt = now -> next;
		(*del)(now -> content);
		free(now);
		now = nxt;
	}
	*lst = NULL;
}
