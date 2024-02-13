/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:56:40 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:37:45 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	sort(t_stak **a, t_stak **b)
{
	if (ft_lstsize(*a) == 2 && (*a)->next->index < (*a)->index)
	{
		swap_a(a);
		return ;
	}
	if (ft_lstsize(*a) == 3)
	{
		sort_three(a);
		return ;
	}
	if (ft_lstsize(*a) == 4)
	{
		sort_four(a, b);
		return ;
	}
	if (ft_lstsize(*a) == 5)
	{
		sort_five(a, b);
		return ;
	}
	else
		sort_all(a, b);
}

void	sort_three(t_stak **a)
{
	if ((*a)->index < (*a)->next->index
		&& (*a)->next->index > (*a)->next->next->index)
		reverse_rotate_a(a);
	else if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
		rotate_a(a);
	if ((*a)->index > (*a)->next->index)
		swap_a(a);
}

void	sort_four(t_stak **a, t_stak **b)
{
	push_a(a, b);
	sort_three(a);
	push_b(b, a);
	if ((*a)->index > (*a)->next->index)
		swap_a(a);
	push_a(a, b);
	sort_three(a);
	push_b(b, a);
}

void	sort_five(t_stak **a, t_stak **b)
{
	int	location;
	int	middle;

	location = get_location_min(a);
	middle = get_middle_stak(*a);
	while (location != 1 && location <= middle)
	{
		rotate_a(a);
		location = get_location_min(a);
	}
	while (location != 1 && location > middle)
	{
		reverse_rotate_a(a);
		location = get_location_min(a);
	}
	push_a(a, b);
	sort_four(a, b);
	push_b(b, a);
}

void	sort_all(t_stak **a, t_stak **b)
{
	int	size_a;
	int	i;
	int	j;

	i = 0;
	size_a = ft_lstsize(*a);
	while (test_order(a) != 1)
	{
		j = 0;
		while (j < size_a && test_order(a) != 1)
		{
			if ((((*a)->index >> i) & 1) == 1)
				rotate_a(a);
			else
				push_a(a, b);
			j++;
		}
		while (*b)
			push_b(b, a);
		i++;
	}
}
