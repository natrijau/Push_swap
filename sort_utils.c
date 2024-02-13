/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:07:05 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:39:34 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_a(t_stak **lst)
{
	int		index;
	long	content;

	index = (*lst)->index;
	content = (*lst)->content;
	(*lst)->index = (*lst)->next->index;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->index = index;
	(*lst)->next->content = content;
	ft_putstr_fd("sa\n", 1);
}

void	push_a(t_stak **lst, t_stak **b)
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
	ft_putstr_fd ("pb\n", 1);
}

void	rotate_a(t_stak **lst)
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
	ft_putstr_fd ("ra\n", 1);
}

int	get_location_min(t_stak **lst)
{
	t_stak	*tmp;
	int		location;

	tmp = *lst;
	location = 1;
	while (tmp->index != 1)
	{
		location++;
		tmp = tmp->next;
	}
	return (location);
}

int	get_middle_stak(t_stak *a)
{
	t_stak	*tmp;
	int		middle;

	tmp = a;
	middle = ft_lstsize(tmp) / 2;
	if (ft_lstsize(tmp) % 2 == 1)
		middle++;
	return (middle);
}
