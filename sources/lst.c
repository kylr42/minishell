#include "minishell.h"

char **ft_lst_to_array(t_list *lst)
{
    size_t size;
    char **arr;

    size = ft_lstsize(lst) + 1;
    arr = ft_allocate(sizeof(char *) * size);
    arr[--size] = NULL;
    while (lst)
    {
        arr[--size] = ft_strdup(lst->content);
        lst = lst->next;
    }
    return (arr);
}

char	*ft_lst_to_str(t_list *lst)
{
    size_t	i;
    char	*str;
    t_list	*cur;
    size_t	size_string;

    i = 0;
    cur = lst;
    size_string = 1;
    while (cur)
    {
        size_string += ft_strlen(cur->content);
        cur = cur->next;
    }
    str = ft_allocate(size_string * sizeof(*str));
    while (lst)
    {
        ft_memcpy(str + i, lst->content, ft_strlen(lst->content));
        i += ft_strlen(lst->content);
        lst = lst->next;
    }
    return (str);
}

t_list	*ft_lstpop_find(t_list **lst, const char *key)
{
    t_list	*elem;
    t_list	*curr;

    elem = NULL;
    curr = *lst;
    if (curr && !ft_strncmp(curr->content, key, ft_keylen(key)))
    {
        elem = curr;
        *lst = elem->next;
        elem->next = NULL;
        return (elem);
    }
    while (curr && curr->next)
    {
        if (!ft_strncmp(curr->next->content, key, ft_keylen(key)))
        {
            elem = curr->next;
            curr->next = curr->next->next;
            elem->next = NULL;
            break ;
        }
        curr = curr->next;
    }
    return (elem);
}
