/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:09:04 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/05 17:44:35 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int	test_max(char *str)
{
	long	nb;
	
	nb = f_atoi(str);
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
		// while (str[i] == ' ')
		// 	i++;
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
			ft_putstr_fd("Its not an integer !\n", 2);
			return (-1);
		}
		if (check_max(av[i]) != 0)
		{
			ft_putstr_fd("It's an integer to long !\n", 2);
			return (-1);	
		}
		i++;
	}
	return (0);
}

void	del(void *del)
{
	(void)del;
}

int	main(int ac, char **av)
{
	t_stak	*lst;
	t_stak	*tmp;

	lst = NULL;
	if (check_arg(ac, av) == -1 || ac <= 1)
		return (-1);
	pars_integer(&lst, ac, av);
	tmp = lst;
	while (lst != NULL)
	{
		printf("numb %ld\n", (long)lst->content);
		lst = lst->next;
	}
	lst = tmp;
	ft_lstclear(&lst, del);
	return (0);
}
