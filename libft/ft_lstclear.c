#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	if (*lst)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}
