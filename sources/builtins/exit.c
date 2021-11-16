/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:07:30 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:07:32 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static u_int8_t	ft_atoi_overflow(const char *str)
{
	int			i;
	int			minus;
	u_int64_t	num;

	i = 0;
	minus = 1;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
		num = (num * 10) + (str[i++] - '0');
	return (num * minus);
}

static bool	ft_isalldigit(char *argv)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	if (argv[i] == '+' || argv[i] == '-')
	{
		sign = 1;
		i++;
	}
	if ((int) ft_strlen(argv) > 21 + sign)
		return (true);
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool	ft_many_args(void)
{
	ft_putstr_fd(RED"exit: ", 2);
	ft_putstr_fd("too many arguments", 2);
	ft_putstr_fd(RESET"\n", 2);
	return (true);
}

static bool	ft_exit_no_num(char *argv)
{
	ft_putstr_fd(SIL"exit: ", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd(": numeric argument required", 2);
	ft_putstr_fd(RESET"\n", 2);
	exit(255);
	return (true);
}

int	ft_exit(char **argv, t_shell *msh)
{
	(void) msh;
	ft_putstr_fd(CYN"exit || bye-bye))\n"RESET, 1);
	if (argv[1] == NULL)
		exit(msh->cmd_status);
	if (ft_isalldigit(argv[1]))
		return (ft_exit_no_num(argv[1]));
	if (ft_split_len(argv) > 2)
		return (ft_many_args());
	else if (ft_split_len(argv) == 2)
		exit(ft_atoi_overflow(argv[1]));
	return (0);
}
