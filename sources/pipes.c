#include "minishell.h"

void ft_run_cmd(t_shell *shell, t_cmd *cmd)
{
    int z;
    char **paths;
    char *cmd_name;

    if (!cmd->arg)
        exit (0);
    z = 0;
    paths = ft_get_paths(shell);
    cmd_name = cmd->arg[0];
    while (ft_gen_next_path(cmd->arg, paths, cmd_name, &z))
    {
        execve(cmd->arg[0], cmd->arg, shell->arr_env);
        if (errno == ENOEXEC)
            exit(0);
        if (errno != 2)
            ft_critical_error(0, cmd_name, 0);
    }
    ft_raise_error(ft_strjoin("shell: Command not found: ", cmd_name), 0);
    exit(127);
}

void ft_run_first_cmd(t_shell *shell, t_cmd *cmd)
{
    cmd->pid = fork();
    if (!cmd->pid)
    {
        ft_signal_in_child();
        if (cmd->next)
            close(cmd->next->std_in);
        ft_get_redirects(cmd, true);
        if (is_builtin(shell, cmd->arg[0]))
        {
            ft_run_builtin(shell, cmd, cmd->arg[0]);
            exit(g_status);
        }
        else
            ft_run_cmd(shell, cmd);
    }
    if (cmd->std_in != STDIN_FILENO)
        close(cmd->std_in);
    if (cmd->std_out != STDOUT_FILENO)
        close(cmd->std_out);
    if (cmd->pid < 0)
    {
        ft_raise_error(0, "shell: fork:");
        g_status = 128;
    }
}

void ft_run_last_cmd(t_shell *shell, t_cmd *cmd)
{

    if (is_builtin(shell, cmd->arg[0]))
    {
        ft_copy_std_io(shell);
        if (!ft_get_redirects(cmd, false))
            ft_run_builtin(shell, cmd, cmd->arg[0]);
        ft_restore_std_io(shell);
    }
    else
    {
        ft_run_first_cmd(shell, cmd);
        if (!g_status)
        {
            waitpid(cmd->pid, &shell->cmd_status, 0);
            g_status = WEXITSTATUS(shell->cmd_status);
            if (!g_status && WIFSIGNALED(shell->cmd_status))
            {
                if (shell->cmd_status == 2 || shell->cmd_status == 3)
                    ft_putendl_fd("", 2);
                g_status = 128 + WTERMSIG(shell->cmd_status);
            }
        }
    }
}

void	ft_wait_pipes(t_shell *shell, t_cmd *last_cmd)
{
    t_cmd	*cmd;

    cmd = shell->cmds;

    while (cmd && cmd->next && cmd != last_cmd)
    {
        close(cmd->pipe_fd[1]);
        close(cmd->pipe_fd[0]);
        cmd = cmd->next;

    }
    cmd = shell->cmds;
    while (cmd && cmd->next && cmd != last_cmd)
    {
        if (cmd->pid)
            waitpid(cmd->pid, 0, 0);
        cmd = cmd->next;
    }
}

void ft_run_pipes(t_shell *shell)
{
    t_cmd *tmp;

    tmp = shell->cmds;
    ft_signal_run_pipes();
    while (tmp && !g_status)
    {
        tmp->arg = ft_lst_to_array(tmp->lst);
        if (!tmp->next)
            ft_run_last_cmd(shell, tmp);
        else
        {
            if (pipe(tmp->pipe_fd) < 0)
            {
                ft_raise_error(NULL, "shell");
                break ;
            }
            tmp->std_out = tmp->pipe_fd[1];
            tmp->next->std_in = tmp->pipe_fd[0];
            ft_run_first_cmd(shell, tmp);
        }
        tmp = tmp->next;
    }
    ft_wait_pipes(shell, tmp);
    ft_signal_main();
}
