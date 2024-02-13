/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:49:22 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:40:08 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	takes_integers(t_stak **lst, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] == ' ')
			i++;
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
		tmp = ft_substr(str, i - j, j);
		if (!(tmp[0] == '\0'))
			ft_lstadd_back(lst, ft_lstnew(0, ft_atoi(tmp)));
		free(tmp);
	}
}

static int	multiple_integer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]) && str[i])
		{
			i++;
		}
		while (str[i] == ' ')
			i++;
		if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i - 1]) != 0)
			return (-1);
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	get_integer(t_stak **lst, char *str)
{
	int	i;

	i = 0;
	if (multiple_integer(str) == 1)
	{
		takes_integers(lst, str);
		return (0);
	}
	if (multiple_integer(str) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else
	{
		ft_lstadd_back(lst, ft_lstnew(0, ft_atoi(str)));
		return (0);
	}
}

int	pars_integer(t_stak **lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (get_integer(lst, av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}
