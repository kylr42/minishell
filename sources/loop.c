#include "minishell.h"

static int ft_check_expand(char **str)
{
    int result;
    char *expansion;


    result = history_expand(*str, &expansion);
    if (result)
        ft_putendl_fd(expansion, 1);
    if (result < 0 || result == 2)
    {
        free(expansion);
        return (1);
    }
    add_history(expansion);
    free(*str);
    *str = ft_strdup(expansion);
    free(expansion);
    return (0);
}

static void	ft_lstclear_cmds(t_cmd **cmd)
{
    t_cmd	*next;

    while (*cmd)
    {
        next = (*cmd)->next;
        ft_lstclear(&(*cmd)->lst, free);
        ft_lstclear(&(*cmd)->redirects, free);
        if ((*cmd)->arg)
            ft_split_free((*cmd)->arg);
        (*cmd)->arg = NULL;
        free(*cmd);
        *cmd = next;
    }
}

static void	ft_clean(t_shell *shell, char *str)
{
    if (shell->cmds)
        ft_lstclear_cmds(&shell->cmds);
    if (ft_strlen(str))
        shell->cmd_status = g_status;
    g_status = 0;
    free(str);
}

int ft_loop(t_shell *shell)
{
    char *str;

    using_history();
    while (true)
    {
        str = readline(shell->ps);
        if (g_status == 130)
        {
            shell->cmd_status = 1;
            g_status = 0;
        }
        if (!str)
            str = ft_strdup("exit");
        else if (ft_check_expand(&str))
            continue ;
        if (!ft_parser(shell, str))
            ft_run_pipes(shell);
        ft_clean(shell, str);
    }
}
