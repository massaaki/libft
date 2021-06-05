#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_lst)
{
	t_list	*current;

	if (!lst || !new_lst)
		return ;
	current = *lst;
	if (current == NULL)
		*lst = new_lst;
	else
	{
		current = ft_lstlast(*lst);
		current->next = new_lst;
	}
}
