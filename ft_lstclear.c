#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	current = *lst;
	if(!del || !current)
		return;
	while (current != NULL)
	{
		ft_lstdelone(current, del);
		current = current->next;
	}
	*lst = NULL;
}
