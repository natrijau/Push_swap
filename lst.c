/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:10:34 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:33:38 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_lstadd_back(t_stak **lst, t_stak *new)
{
	t_stak	*stock;

	if (!lst || !new)
		return ;
	if (!(*lst))
		(*lst) = new;
	else
	{
		stock = ft_lstlast(*lst);
		stock->next = new;
	}
}

void	ft_lstadd_front(t_stak **lst, t_stak *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_stak **lst, void (*del)(void *))
{
	t_stak	*stock;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		stock = (*lst)->next;
		free(*lst);
		*lst = stock;
	}
	*lst = (NULL);
}

int	ft_lstsize(t_stak *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_stak	*ft_lstnew(int index, long content)
{
	t_stak	*lst;

	lst = NULL;
	lst = (t_stak *)malloc(sizeof(t_stak));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->index = index;
	lst->next = (NULL);
	return (lst);
}
