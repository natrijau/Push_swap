/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:27:38 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:38:29 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stak	*ft_lstlast(t_stak *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	del(void *del)
{
	(void)del;
}
