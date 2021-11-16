#ifndef MINISHELL_BUILTINS_H
#define MINISHELL_BUILTINS_H

# include "includes.h"

int     ft_pwd(void);
int		ft_echo(char **str);
int     ft_env(t_shell *shell);
int     ft_exit(char **argv, t_shell *msh);

#endif //MINISHELL_BUILTINS_H
