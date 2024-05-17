/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdaems <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:05:51 by fdaems            #+#    #+#             */
/*   Updated: 2024/04/30 13:14:34 by fdaems           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

void				copy_str(t_list **lst, char *d);
void				ft_lstadd_back(t_list **lst, char *buf);
t_list				*ft_lstlast(t_list *lst);
char				*get_next_line(int fd);
char				*make_string(t_list **lst);
unsigned int		count_chars(t_list **lst);
t_list				*make_new_line(t_list **lst, int fd);
int					is_new_line(t_list *lst);
void				ft_lstclear(t_list **lst, t_list *new, char *buf);
void				start_new(t_list **lst);

#endif
