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
# include "libft/libft.h"
// DEBUG

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define MAG   "\x1B[35m"
# define RESET "\x1B[0m"

# define BUIL_CMD   "exit:echo:export:unset:env:cd:pwd"


typedef struct s_cmd
{
    char			**arg;
//    t_list			*lst_arg;
//    t_list			*redirects;
//    int				pipe_fd[2];
//    int				in;
//    int				out;
//    pid_t			pid;
//    bool			is_fork;
    struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
    char    *ps;
    t_cmd   *cmd;
    t_list  *env;
    char    **arr_env;
    char    **buil_cmd;

}	t_shell;


int		echo(char **str);
int     ft_loop(t_shell *shell);
void    *ft_allocate(size_t size);
char    **ft_lst_to_array(t_list *lst);
void    ft_init(t_shell *shell, char *envp[]);


#endif //MINISHELL_H