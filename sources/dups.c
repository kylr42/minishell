/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dups.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:19:17 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 07:19:19 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_copy_std_io(t_shell *shell)
{
	shell->old_in = dup(STDIN_FILENO);
	shell->old_out = dup(STDOUT_FILENO);
	if (shell->old_in < 0 || shell->old_out < 0)
		ft_raise_error(0, 0);
}

void	ft_restore_std_io(t_shell *shell)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	if (dup2(shell->old_in, STDIN_FILENO) < 0)
		ft_raise_error(0, 0);
	if (dup2(shell->old_out, STDOUT_FILENO) < 0)
		ft_raise_error(0, 0);
	close(shell->old_in);
	close(shell->old_out);
}

void	ft_dup_cmd_io(t_cmd *cmd)
{
	if (cmd->std_in != STDIN_FILENO)
	{
		if (dup2(cmd->std_in, STDIN_FILENO) < 0)
		{
			if (cmd->is_fork)
				ft_critical_error(0, 0, 0);
			return (ft_raise_error(0, 0));
		}
		close(cmd->std_in);
	}
	if (cmd->std_out != STDOUT_FILENO)
	{
		if (dup2(cmd->std_out, STDOUT_FILENO) < 0)
		{
			if (cmd->is_fork)
				ft_critical_error(0, 0, 0);
			return (ft_raise_error(0, 0));
		}
		close(cmd->std_out);
	}
}
