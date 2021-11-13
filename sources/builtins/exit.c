#include "../../includes/minishell.h"

static bool	ft_isalldigit(char *argv)
{
    int	i;
    int	sign;

    sign = 0;
    i = 0;
    if (argv[i] == '+' || argv[i] == '-')
    {
        sign = 1;
        i++;
    }
    if ((int)ft_strlen(argv) > 21 + sign)
        return (true);
    while (argv[i])
    {
        if (ft_isdigit(argv[i]) == 0)
            return (true);
        i++;
    }
    return (false);
}

static	bool	ft_many_args(void)
{
    ft_putstr_fd(RED"exit: ", 2);
    ft_putstr_fd("too many arguments", 2);
    ft_putstr_fd(RESET"\n", 2);
    return (true);
}

static void	ft_exit_no_num(char *argv)
{
    ft_putstr_fd("exit: ", 2);
    ft_putstr_fd(argv, 2);
    ft_putstr_fd(": numeric argument required", 2);
    ft_putstr_fd("\n", 2);
    exit(255);
}

int	ft_exit(char **argv, t_shell *msh)
{
    (void)msh;
    if (argv[1] == NULL)
        exit(msh->cmd_status);
    if (ft_isalldigit(argv[1]))
        ft_exit_no_num(argv[1]);
    if (ft_split_len(argv) > 2)
        return (ft_many_args());
    else if (ft_split_len(argv) == 2)
        exit(ft_atoi(argv[1]));
    return (0);
}