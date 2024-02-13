/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:10:52 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:19:24 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	test_order(t_stak **a)
{
	t_stak	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_integer(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isdigit(str[i]) && str[i])
			return (-1);
		while (ft_isdigit(str[i]) && str[i])
		{
			count++;
			i++;
		}
		if (str[i])
			continue ;
	}
	if (count == 0)
		return (-1);
	return (0);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_integer(av[i]) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		if (check_max(av[i]) != 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_double(t_stak	**lst)
{
	t_stak	*tmp;
	t_stak	*tmp2;
	long	content;

	tmp = *lst;
	while (tmp->next != NULL)
	{
		content = tmp->content;
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (content == tmp2->content)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	take_index(t_stak **lst)
{
	t_stak	*tmp;
	t_stak	*tmp2;
	int		i;

	tmp = *lst;
	tmp2 = *lst;
	while (tmp != NULL)
	{
		i = 1;
		while (tmp2 != NULL)
		{
			if (tmp->content > tmp2->content)
				i++;
			tmp2 = tmp2->next;
		}
		tmp2 = *lst;
		tmp->index = i;
		tmp = tmp->next;
	}
}
