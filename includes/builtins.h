/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 06:54:49 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 06:55:01 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "includes.h"

int		ft_pwd(void);
int		ft_echo(char **str);
int		ft_env(t_shell *shell);
int		ft_exit(char **argv, t_shell *msh);
int		ft_cd(char **argv, t_shell *shell);
int		ft_unset(char **argv, t_shell *shell);
int		ft_export(char **argv, t_shell *shell);

// EXPORT_UTILS
int		ft_export_error(char *exp);

void	print_export(char **env);
void	ft_sort_env(t_shell *shell, int len_env);

// CD_UTILS

int		ft_chdir_error(char *dir);
int		ft_set_new_pwd(t_shell *shell);
int		ft_set_new_oldpwd(char *pwd_old, t_shell *shell);

#endif //BUILTINS_H
