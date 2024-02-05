/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:19:47 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/05 16:59:23 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
/*
Libère la mémoire de l’élément passé en argument en
utilisant la fonction ’del’ puis avec free(3). La
mémoire de ’next’ ne doit pas être free.
*/
void	ft_lstdelone(t_stak *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// /Ajoute l’élément ’new’ à la fin de la liste.
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

// Ajoute l’élément ’new’ au début de la liste.
void	ft_lstadd_front(t_stak **lst, t_stak *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
Supprime et libère la mémoire de l’élément passé en
paramètre, et de tous les éléments qui suivent, à
l’aide de ’del’ et de free(3)
Enfin, le pointeur initial doit être mis à NULL.
*/
void	ft_lstclear(t_stak **lst, void (*del)(void *))
{
	t_stak	*stock;

	if (!lst || !del)
		return ;
	while ((*lst) != NULL)
	{
		stock = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = stock;
	}
	*lst = (NULL);
}

// Renvoie le dernier élément de la liste.
t_stak	*ft_lstlast(t_stak *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

//Compte le nombre d’éléments de la liste.
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

/*
Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre
’content’. La variable ’next’ est initialisée à
NULL.
*/
t_stak	*ft_lstnew(void *content)
{
	t_stak	*lst;

	lst = NULL;
	lst = (t_stak *)malloc(sizeof(t_stak));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = (NULL);
	return (lst);
}

/*
Itère sur la liste ’lst’ et applique la fonction
’f ’au contenu de chaque élément. Crée une nouvelle
liste résultant des applications successives de
’f’. La fonction ’del’ est là pour détruire le
contenu d’un élément si nécessaire.
*/
t_stak	*ft_lstmap(t_stak *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stak	*node;

	if (!lst || !(f) || !(del))
		return (NULL);
	while (lst != NULL)
	{
		node = (f)(lst->content);
		if (!node)
			ft_lstclear(&node, (del));
		lst = lst->next;
	}
	lst = (NULL);
	return (node);
}

/*
Itère sur la liste ’lst’ et applique la fonction
’f’ au contenu chaque élément.
*/
void	ft_lstiter(t_stak *lst, void (*f)(void *))
{
	if (!lst || !(f))
		return ;
	while (lst != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}

long	f_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	sign;
	long			nb;

	i = 0;
	nb = 0;
	sign = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign + 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	if (sign == 1)
		nb = nb * -1;
	return (nb);
}
