#include "minishell.h"

int	ft_pwd(void)
{
    char	*pwd;

    pwd = ft_allocate(4096);
    if (getcwd(pwd, 4096))
    {
        ft_putstr_fd(pwd, 1);
        free(pwd);
        write(1, "\n", 1);
        return (0);
    }
    ft_print_errno();
    free(pwd);
    return (1);
}