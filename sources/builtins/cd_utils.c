/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:07:03 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:07:05 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	chdir_error(char *dir)
{
	ft_putstr_fd("shell: cd: ", 2);
	ft_putstr_fd(dir, 2);
	ft_putstr_fd(": ", 2);
	return (ft_print_errno());
}

int	set_new_oldpwd(char *pwd_old, t_shell *shell)
{
	char	*pwd;

	pwd = ft_strjoin("OLDPWD=", pwd_old);
	ft_update_el_env(shell, pwd);
	free(pwd);
	return (0);
}

int	set_new_pwd(t_shell *shell)
{
	char	*new_pwd;
	char	*tmp;
	char	*pwd;

	tmp = ft_allocate(1024);
	pwd = getcwd(tmp, 1024);
	if (pwd == NULL)
	{
		free(tmp);
		return (ft_print_errno());
	}
	new_pwd = ft_strjoin("PWD=", pwd);
	ft_update_el_env(shell, new_pwd);
	free(new_pwd);
	free(tmp);
	return (0);
}
