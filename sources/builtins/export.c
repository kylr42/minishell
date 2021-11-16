#include "minishell.h"

static int	check_export(char *exp)
{
    int	i;

    i = 0;
    if (exp[0] == '=' || ft_isdigit(exp[0]) || !ft_isalpha(exp[0]))
        return (ft_write_error_export(exp));
    while (exp[i] && exp[i] != '=')
    {
        if (!ft_isalpha(exp[i]) && !ft_isdigit(exp[i]))
            return (ft_write_error_export(exp));
        i++;
    }
    return (0);
}

int	ft_export(char **argv, t_shell *shell)
{
    int	i;
    int	ret_vel;

    i = 1;
    ret_vel = 0;
    if (ft_split_len(argv) == 1)
    {
        sort_the_env(shell, ft_split_len(shell->arr_env));
        print_export(shell->arr_env);
        return (ret_vel);
    }
    while (argv[i])
    {
        if (!check_export(argv[i]))
            ft_update_el_env(shell, argv[i]);
        else
            ret_vel = 1;
        i++;
    }
    return (ret_vel);
}