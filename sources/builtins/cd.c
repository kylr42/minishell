/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:06:56 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:06:58 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_change_dir_utils(char *oldpwd, char *dir, t_shell *shell)
{
	if (chdir(dir) == -1)
		return (ft_chdir_error(dir));
	if (oldpwd)
		if (ft_set_new_oldpwd(oldpwd, shell) != 0)
			return (ft_print_errno());
	if (ft_set_new_pwd(shell) != 0)
		return (ft_print_errno());
	return (0);
}

int	ft_change_dir(char *dir, t_shell *shell)
{
	char	*oldpwd;
	char	*tmp;
	int		ret_v;

	tmp = ft_calloc(1024, 1);
	if (!tmp)
		ft_print_errno();
	oldpwd = getcwd(tmp, 1024);
	ret_v = ft_change_dir_utils(oldpwd, dir, shell);
	free(tmp);
	return (ret_v);
}

int	ft_cd_to_oldpwd(t_shell *shell)
{
	char	*oldpwd;
	int		r_vel;

	oldpwd = ft_get_el_env(shell, "OLDPWD");
	if (oldpwd[0] == '\0')
	{
		ft_putstr_fd(RED"shell: cd : HOME not set \n"RESET, 2);
		return (1);
	}
	r_vel = ft_change_dir(oldpwd, shell);
	free(oldpwd);
	return (r_vel);
}

static int	ft_cd_work(char **argv, t_shell *shell)
{
	int		i;
	char	*tmp;
	char	*home;

	if (!ft_strncmp(argv[1], "-", 1))
		return (ft_cd_to_oldpwd(shell));
	if (!ft_strncmp(argv[1], "~", 1)
		&& (argv[1][1] == '\0' || argv[1][1] == '/'))
	{
		home = ft_get_el_env(shell, "HOME");
		tmp = ft_strjoin(home, &argv[1][1]);
		free(home);
		i = ft_change_dir(tmp, shell);
		free(tmp);
		return (i);
	}
	else
		return (ft_change_dir(argv[1], shell));
}

int	ft_cd(char **argv, t_shell *shell)
{
	char	*home;
	int		r_vel;

	if (ft_split_len(argv) > 2)
	{
		ft_putstr_fd("shell: cd: to many arguments\n", 2);
		return (1);
	}
	if (ft_split_len(argv) == 1)
	{
		home = ft_get_el_env(shell, "HOME");
		if (home[0] == '\0')
		{
			ft_putstr_fd(RED"shell: cd : HOME not set \n"RESET, 2);
			free(home);
			return (1);
		}
		r_vel = ft_change_dir(home, shell);
		free(home);
		return (r_vel);
	}
	if (ft_split_len(argv) == 2)
		return (ft_cd_work(argv, shell));
	return (0);
}
