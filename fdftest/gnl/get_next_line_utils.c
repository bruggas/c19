/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:48:42 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/30 12:51:42 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, char *buf)
{
	t_list	*last;
	t_list	*new;

	last = ft_lstlast(*lst);
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = buf;
	if (!last)
		*lst = new;
	else
		last->next = new;
	new->content = buf;
	new->next = NULL;
}

void	copy_str(t_list **lst, char *d)
{
	unsigned int	i;
	unsigned int	k;
	t_list			*buf;

	k = 0;
	i = 0;
	buf = *lst;
	if (!buf)
		return ;
	while (buf)
	{
		k = 0;
		while (buf->content[k])
		{
			if (buf->content[k] == '\n')
			{
				d[i] = '\n';
				d[i + 1] = '\0';
				return ;
			}
			d[i++] = buf->content[k++];
		}
		buf = buf->next;
	}
	d[i] = '\0';
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear(t_list **lst, t_list *new, char *buf)
{
	t_list	*nxt;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		nxt = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = nxt;
	}
	*lst = NULL;
	if (new->content[0])
		*lst = new;
	else
	{
		free(buf);
		free(new);
	}
}

void	start_new(t_list **lst)
{
	t_list	*new;
	t_list	*now;
	int		i;
	int		j;
	char	*buf;

	j = 0;
	i = 0;
	now = ft_lstlast(*lst);
	while (now->content[i] != '\n' && now->content[i])
		i++;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	new = malloc(sizeof(t_list));
	if (!buf || !new)
		return ;
	if (now->content[i] == '\n')
		i++;
	while (now->content[i])
		buf[j++] = now->content[i++];
	buf[j] = '\0';
	new->content = buf;
	new->next = NULL;
	ft_lstclear(lst, new, buf);
}
