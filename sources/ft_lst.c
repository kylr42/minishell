#include "../minishell.h"

void *ft_allocate(size_t size)
{
    void *arr;

    arr = malloc(size);
    if (arr)
        return (arr);
    ft_putendl_fd(RED"Er.: Cannot allocate memory"RESET, 2);
    exit(errno);
}

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