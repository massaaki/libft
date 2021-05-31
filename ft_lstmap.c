#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_el;
	t_list	*first_new_el;
	t_list	*current;

	if(!lst || !del)
		return (NULL);
	first_new_el = NULL;
	current = lst;
	while(current != NULL)
	{
		new_el = ft_lstnew(f(current->content));
		if (!new_el)
		{
			ft_lstclear(&first_new_el, del);
			return (NULL);
		}
		ft_lstadd_back(&first_new_el, new_el);
		current = current->next;
	}
	return (first_new_el);
}
