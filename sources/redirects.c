#include "minishell.h"

void	ft_redirect_open_file(t_cmd *cmd, char *fname, int mode)
{
    if (mode == 1)
    {
        if (cmd->std_in != STDIN_FILENO)
            close(cmd->std_in);
        cmd->std_in = open(fname, O_RDONLY);
    }
    else
    {
        if (cmd->std_out != STDOUT_FILENO)
            close(cmd->std_out);
        if (mode == 2)
            cmd->std_out = open(fname, O_RDWR | O_CREAT | O_TRUNC, 00774);
        else if (mode == 3)
            cmd->std_out = open(fname, O_WRONLY | O_APPEND | O_CREAT, 00774);
    }
    if (cmd->std_in < 0 || cmd->std_out < 0)
    {
        if (cmd->is_fork)
            ft_critical_error(NULL, fname, 1);
        else
            ft_raise_error(NULL, fname);
    }
}

void	ft_double_left_arrow_read(t_cmd *cmd, char *stop_word)
{
    char	*line;

    while (true)
    {
        line = readline(GRN"> "RESET);
        if (!ft_strncmp(line, stop_word, ft_strlen(stop_word) + 1))
            break ;
        ft_putendl_fd(line, cmd->std_out);
        free(line);
    }
    close(cmd->std_out);
    exit(0);
}

void	ft_double_left_arrow(t_cmd *cmd, char *stop_word)
{
    int	fd[2];
    int	pid;

    if (cmd->std_in)
        close(cmd->std_in);
    if (pipe(fd) < 0)
    {
        if (cmd->is_fork)
            ft_critical_error(0, 0, 0);
        else
            ft_raise_error(NULL, NULL);
    }
    pid = fork();
    if (pid)
    {
        waitpid(pid, 0, 0);
        cmd->std_in = fd[0];
        close(fd[1]);
    }
    else
    {
        close(fd[0]);
        cmd->std_out = fd[1];
        ft_double_left_arrow_read(cmd, stop_word);
    }
}

int	ft_get_redirects(t_cmd *cmd, bool is_fork)
{
    t_list	*redir;

    cmd->is_fork = is_fork;
    redir = cmd->redirects;
    while (redir && !g_status)
    {
        if (!ft_strncmp(redir->content, "<<", 2))
            ft_double_left_arrow(cmd, redir->content + 2);
        else if (!ft_strncmp(redir->content, "<", 1))
            ft_redirect_open_file(cmd, redir->content + 1, 1);
        else if (!ft_strncmp(redir->content, ">>", 2))
            ft_redirect_open_file(cmd, redir->content + 2, 3);
        else if (!ft_strncmp(redir->content, ">", 1))
            ft_redirect_open_file(cmd, redir->content + 1, 2);
        redir = redir->next;
    }
    if (!g_status)
        ft_dup_cmd_io(cmd);
    return (g_status);
}

