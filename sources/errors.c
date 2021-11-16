/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:31:38 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 07:39:57 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_error(char *error)
{
	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putendl_fd(RESET, STDERR_FILENO);
}

void	ft_critical_error(char *msg, char *errno_msg, int err)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	else
		perror(errno_msg);
	if (err)
		exit(err);
	else if (errno)
		exit(errno);
	else
		exit(1);
}

void	ft_raise_error(char *error_msg, char *errno_msg)
{
	if (error_msg)
		ft_put_error(error_msg);
	else
		perror(errno_msg);
	if (errno)
		g_status = errno;
	else
		g_status = 1;
}

void	ft_raise_error_n(char *error_msg, int code)
{
	ft_put_error(error_msg);
	g_status = code;
}

int	ft_print_errno(void)
{
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 2);
	return (1);
}
