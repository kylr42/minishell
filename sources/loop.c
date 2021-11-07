#include "../minishell.h"

int ft_check_expand(char **str)
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

//void ft_run_commands(t_shell *shell)
//{
//    t_cmd *tmp;
//
//    tmp = shell->cmd;
//    while (tmp && !g_status)
//    {
//        tmp->arg = ft_lst_to_array(tmp->lst);
//    }
//}

int ft_loop(t_shell *shell)
{
    char *str;

    using_history();
    while (true)
    {
        str = readline(shell->ps);
        if (!str)
            str = ft_strdup("exit");
        if (*str)
            if (ft_check_expand(&str))
                continue ;
        if (!ft_parser(shell, str))
//            ft_run_commands(shell);
        free(str);
    }
}
