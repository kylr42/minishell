#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    if (*lst)
    {
        ft_lstclear(&(*lst)->next, del);
        if (del)
            del((*lst)->content);
        free(*lst);
    }
    *lst = NULL;
}
