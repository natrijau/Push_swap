/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:12:24 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:35:20 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_b(t_stak **lst)
{
	int		index;
	long	content;

	index = (*lst)->index;
	content = (*lst)->content;
	(*lst)->index = (*lst)->next->index;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->index = index;
	(*lst)->next->content = content;
}

void	push_b(t_stak **lst, t_stak **b)
{
	t_stak	*tmp;

	tmp = *lst;
	if (!tmp)
		return ;
	if ((*b) == NULL)
		(*b) = ft_lstnew(tmp->index, tmp->content);
	else
		ft_lstadd_front(b, ft_lstnew(tmp->index, tmp->content));
	*lst = (*lst)->next;
	free(tmp);
	ft_putstr_fd ("pa\n", 1);
}

void	rotate_b(t_stak **lst)
{
	int		index;
	int		content;
	t_stak	*tmp;
	t_stak	*tmp2;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp2 = (*lst)->next;
	tmp = *lst;
	index = tmp->index;
	content = tmp->content;
	free(tmp);
	ft_lstadd_back(&tmp2, ft_lstnew(index, content));
	*lst = tmp2;
	ft_putstr_fd ("rb\n", 1);
}

void	reverse_rotate_a(t_stak **lst)
{
	t_stak	*tmp;
	int		index;
	int		content;	

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = ft_lstlast(*lst);
	index = tmp->index;
	content = tmp->content;
	tmp = *lst;
	ft_lstadd_front(lst, ft_lstnew(index, content));
	while ((tmp)->next->next != NULL)
		(tmp) = (tmp)->next;
	free(tmp->next);
	(tmp)->next = NULL;
	ft_putstr_fd ("rra\n", 1);
}

void	reverse_rotate_b(t_stak **lst)
{
	t_stak	*tmp;
	int		index;
	int		content;	

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = ft_lstlast(*lst);
	index = tmp->index;
	content = tmp->content;
	tmp = *lst;
	ft_lstadd_front(lst, ft_lstnew(index, content));
	while ((tmp)->next->next != NULL)
		(tmp) = (tmp)->next;
	free(tmp->next);
	(tmp)->next = NULL;
}
