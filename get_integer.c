/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:49:22 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/05 17:48:05 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

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
		tmp = ft_strdup(&str[i - j]);
		ft_lstadd_back(lst, ft_lstnew((void *)f_atoi(tmp)));
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
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	get_integer(t_stak **lst, char *str)
{
	int	i;

	i = 0;
	if (multiple_integer(str) != 0)
		takes_integers(lst, str);
	else
		ft_lstadd_back(lst, ft_lstnew((void *)f_atoi(str)));
	// *lst = ft_lstnew((void *)f_atoi(str));
}

void	pars_integer(t_stak **lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		get_integer(lst, av[i]);
		i++;
	}
}
