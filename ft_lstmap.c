#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_el;
	t_list	*first_new_el;

	if (!lst || !f)
		return (NULL);
	new_el = ft_lstnew(f(lst->content));
	if (!new_el)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	first_new_el = new_el;
	lst = lst->next;
	while (lst != NULL)
	{
		new_el = ft_lstnew(f(lst->content));
		if (!new_el)
		{
			ft_lstclear(&first_new_el, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&first_new_el, new_el);
	}
	return (first_new_el);
}
