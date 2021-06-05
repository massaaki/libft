#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		cont;

	current = lst;
	cont = 0;
	while (current != NULL)
	{
		current = current->next;
		cont ++;
	}
	return (cont);
}
