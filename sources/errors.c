#include "../minishell.h"

int ft_raise_error(char *error, int code)
{
    ft_putstr_fd(RED, STDERR_FILENO);
    ft_putstr_fd(error, STDERR_FILENO);
    ft_putendl_fd(RESET, STDERR_FILENO);
    g_status = code;
    return (-1);
}
