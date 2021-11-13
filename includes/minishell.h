/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:07:54 by jsiona            #+#    #+#             */
/*   Updated: 2021/09/21 15:07:56 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

// DEBUG (change to prod)
# include "../libft/libft.h"
// DEBUG

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define MAG   "\x1B[35m"
# define RESET "\x1B[0m"

# define BUIL_CMD   "exit"

# define ERR_PIPE	"shell: Syntax error near unexpected token '|'"
# define ERR_NEWL	"shell: Syntax error near newline"
# define ERR_MLC    "shell: Cannot allocate memory"
# define ERR_TKN	"shell: syntax error near unexpected token: "


typedef struct s_cmd
{
    char			**arg;
    t_list			*lst;
    t_list			*redirects;
    int				pipe_fd[2];
    int				std_in;
    int				std_out;
    pid_t			pid;
    bool			is_fork;
    struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
    char    *ps;
    t_list  *env;
    t_cmd   *cmd;
    t_cmd   *cmds;
    int     old_in;
    int     old_out;
    int     cmd_status;
    char    **arr_env;
    char    **buil_cmd;
    char    hostname[7];
}	t_shell;

int     g_status;

int     ft_pwd(void);
int		echo(char **str);
int     print_errno(void);
int     ft_env(t_shell *shell);
int     ft_loop(t_shell *shell);
int     ft_split_len(char **arr);
int     ft_skip_gap(const char *str);
int     ft_exit(char **argv, t_shell *msh);
int     ft_parser(t_shell *shell, char *str);
int     is_builtin(t_shell *shell, char *name);
int     gen_next_path(char **argv, char **paths, char *name);
int     ft_get_redirects(t_cmd *cmd, bool is_fork);

char	*ft_lst_to_str(t_list *lst);
char    **ft_get_paths(t_shell *shell);
char    **ft_lst_to_array(t_list *lst);
char	*ft_get_key(bool digit, char *s, size_t *i);
char	*ft_get_el_env(t_shell *shell, const char *key);

void	ft_signal_main(void);
void	ft_signal_pipes(int sig);
void	ft_signal_in_child(void);
void	ft_signal_run_pipes(void);
void    *ft_allocate(size_t size);
void	ft_split_free(char **arr);
void	ft_dup_cmd_io(t_cmd *cmd);
void    ft_init_ps(t_shell *shell);
void    ft_run_pipes(t_shell *shell);
void	ft_copy_std_io(t_shell *shell);
void	ft_restore_std_io(t_shell *shell);

void    ft_init(t_shell *shell, char *envp[]);
void	ft_cmd_add_back(t_cmd **lst, t_cmd *new);
void	ft_raise_error_n(char *error_msg, int code);
void    rl_replace_line(const char *buffer, int val);
void	ft_envadd_back(t_list	**chars, char *env_val);
void	ft_raise_error(char *error_msg, char *errno_msg);
void	ft_delete_el_env(t_shell *shell, const char *key);
void	ft_update_el_env(t_shell *shell, const char *keyval);
void	ft_critical_error(char *msg, char *errno_msg, int err);
void	ft_run_builtin(t_shell *shell, t_cmd *cmd, char *name);
void	ft_add_keyword(t_shell *shell, t_list **chars, bool is_redirect);

t_cmd   *ft_allocate_cmd(void);
size_t	ft_keylen(const char *keyval);
t_list	*ft_lstpop_find(t_list **lst, const char *key);

#endif //MINISHELL_H
