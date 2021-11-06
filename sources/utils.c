#include "../minishell.h"

void	ft_cmd_add_back(t_cmd **lst, t_cmd *new)
{
    t_cmd   *curr;

    curr = *lst;
    if (curr)
    {
        while (curr->next)
            curr = curr->next;
        curr->next = new;
    }
    else
        *lst = new;
}

t_cmd *ft_allocate_cmd(void)
{
    t_cmd *cmd;

    cmd = ft_allocate(sizeof(t_cmd));
    cmd->next = NULL;
    cmd->arg = NULL;
    return (cmd);
}

void *ft_allocate(size_t size)
{
    void *arr;

    arr = ft_calloc(1, size + 1);
    if (arr)
        return (arr);
    ft_raise_error(ERR_MLC, 1);
    exit(errno);
}

void	ft_split_free(char **arr)
{
    int	i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}