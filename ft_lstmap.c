#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_el;
	t_list	*first_new_el;
	void	*temp;

	if (!lst || !f)
		return (NULL);
	first_new_el = NULL;
	while (lst != NULL)
	{
		temp = f(lst->content);
		new_el = ft_lstnew(temp);
		if (!new_el)
		{
			ft_lstclear(&first_new_el, del);
			del(temp);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&first_new_el, new_el);
	}
	return (first_new_el);
}
