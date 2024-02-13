/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <natrijau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:35:52 by natrijau          #+#    #+#             */
/*   Updated: 2024/02/13 15:36:36 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_stak
{
	long			content;
	int				index;
	int				middle;
	struct s_stak	*next;
}	t_stak;

typedef struct s_st
{
	t_stak	*a;
	t_stak	*b;
}	t_st;

t_stak	*ft_lstlast(t_stak *lst);
t_stak	*ft_lstnew(int index, long content);
void	ft_lstadd_back(t_stak **lst, t_stak *new);
void	ft_lstadd_front(t_stak **lst, t_stak *new);
void	ft_lstclear(t_stak **lst, void (*del)(void *));
int		ft_lstsize(t_stak *lst);
void	reverse_rotate(t_stak **lst);
void	reverse_rotate_b(t_stak **lst);
void	swap_a(t_stak **lst);
void	swap_b(t_stak **lst);
void	push_a(t_stak **lst, t_stak **b);
void	push_b(t_stak **lst, t_stak **b);
void	rotate_a(t_stak **lst);
void	rotate_b(t_stak **lst);
void	reverse_rotate_a(t_stak **lst);
void	reverse_rotate_b(t_stak **lst);
void	sort(t_stak **a, t_stak **b);
void	sort_three(t_stak **a);
void	sort_four(t_stak **a, t_stak **b);
void	sort_five(t_stak **a, t_stak **b);
void	sort_all(t_stak **a, t_stak **b);
void	take_index(t_stak **lst);
void	del(void *del);
int		get_integer(t_stak **lst, char *str);
int		pars_integer(t_stak **lst, int ac, char **av);
int		check_max(char *str);
int		get_location_min(t_stak **lst);
int		get_middle_stak(t_stak *a);
int		test_order(t_stak **a);
int		check_arg(int ac, char **av);
int		check_double(t_stak	**lst);
int		check_integer(char *str);

#endif