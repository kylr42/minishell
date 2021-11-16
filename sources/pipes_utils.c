#include "minishell.h"

int	ft_is_path(char *s)
{
    while (*s && !ft_isalnum(*s))
        if (*s++ == '/')
            return (true);
    return (false);
}

int	ft_gen_next_path(char **argv, char **paths, char *name, int *z)
{
    char		*temp;

    if (*z > 1)
        free(argv[0]);
    if (*z > ft_split_len(paths) || (!paths[0] && !ft_is_path(name)))
    {
        *z = 0;
        argv[0] = name;
        return (0);
    }
    if (!*z && !ft_is_path(name))
        (*z)++;
    if (*z)
    {
        temp = ft_strjoin(paths[(*z) - 1], "/");
        argv[0] = ft_strjoin(temp, name);
        if (!temp || !argv[0])
            ft_critical_error(0, 0, 0);
        free(temp);
    }
    (*z)++;
    return (1);
}

char **ft_get_paths(t_shell *shell)
{
    char **paths;
    char *tmp;

    tmp = ft_get_el_env(shell, "PATH");
    paths = ft_split(tmp, ':');
    free(tmp);
    return (paths);
}

void	ft_run_builtin(t_shell *shell, t_cmd *cmd, char *name)
{
    (void) shell;
    (void) cmd;
    if (!ft_strncmp(name, "echo", ft_strlen(name)))
        g_status = ft_echo(cmd->arg);
//    else if (!ft_strncmp(name, "cd", ft_strlen(name)))
//        g_status = ft_cd(cmd->arg, shell);
//    else if (!ft_strncmp(name, "pwd", ft_strlen(name)))
//        g_status = ft_pwd();
//    else if (!ft_strncmp(name, "export", ft_strlen(name)))
//        g_status = ft_export(cmd->arg, shell);
//    else if (!ft_strncmp(name, "unset", ft_strlen(name)))
//        g_status = ft_unset(cmd->arg, shell);
    else if (!ft_strncmp(name, "env", ft_strlen(name)))
        g_status = ft_env(shell);
    else if (!ft_strncmp(name, "exit", ft_strlen(name)))
        g_status = ft_exit(cmd->arg, shell);
    else
        ft_putendl_fd("Impossible!", 2);
}

int	is_builtin(t_shell *shell, char *name)
{
    size_t	i;

    if (!name)
        return (false);
    i = 0;
    while (shell->buil_cmd[i])
        if (!ft_strncmp(shell->buil_cmd[i++], name, ft_strlen(name)))
            return (true);
    return (false);
}
