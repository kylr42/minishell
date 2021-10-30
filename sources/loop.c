#include "../minishell.h"

//void ft_parse_pipes(char *str)
//{
//
//}

//int ft_parse(t_shell *shell, char *str)
//{
//
//}

int ft_loop(t_shell *shell)
{
    char *str;

    while (true)
    {
        str = readline(shell->ps);
        if (!str)
            str = ft_strdup("exit");
        if (*str)
            add_history(str);
//        ft_parse(shell, str);
    }
    return (0);
}
