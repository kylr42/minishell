#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *tmp;
    t_list *entry;

    entry = *lst;
    while (entry)
    {
        tmp = entry->next;
        if (del)
        {
            del(entry->content);
        }
        free(entry);
        entry = tmp;
    }
    *lst = NULL;
}
