/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:09:04 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:36:58 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	test_max(char *str)
{
	long	nb;

	nb = ft_atoi(str);
	if (nb > 2147483647 || nb < -2147483648)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}

int	check_max(char *str)
{
	int		i;
	char	*temp;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			j++;
		}
		while (ft_isdigit(str[i]))
		{
			j++;
			i++;
		}
		temp = ft_strdup(&str[i - j]);
		if (test_max(temp) != 0)
			return (-1);
		while (str[i] == ' ')
			i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stak	*a;
	t_stak	*b;

	b = NULL;
	a = NULL;
	if (check_arg(ac, av) == -1 || ac <= 1)
		return (-1);
	if (pars_integer(&a, ac, av) != 0 || check_double(&a) != 0)
	{
		ft_lstclear(&a, del);
		return (-1);
	}
	take_index(&a);
	if (test_order(&a) != 0)
	{
		ft_lstclear(&a, del);
		return (-1);
	}
	sort(&a, &b);
	ft_lstclear(&a, del);
	return (0);
}
