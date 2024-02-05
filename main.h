#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_stak
{
	void	*content;

	struct s_stak	*next;
}	t_stak;

void	ft_lstdelone(t_stak *lst, void (*del)(void*));
void	ft_lstadd_back(t_stak **lst, t_stak *new);
void	ft_lstadd_front(t_stak **lst, t_stak *new);
void	ft_lstclear(t_stak **lst, void (*del)(void *));
void	ft_lstiter(t_stak *lst, void (*f)(void *));
void	pars_integer(t_stak **lst, int ac, char **av);
void	get_integer(t_stak **lst, char *str);
t_stak	*ft_lstlast(t_stak *lst);
t_stak	*ft_lstnew(void *content);
t_stak	*ft_lstmap(t_stak *lst, void *(*f)(void *), void (*del)(void *));
int		ft_lstsize(t_stak *lst);
int		check_max(char *str);
long	f_atoi(const char *nptr);

#endif