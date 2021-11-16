/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:07:54 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:07:56 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_put_str_until_chr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 61)
	{
		write(1, &str[i], 1);
		i++;
	}
}

static void	ft_put_str_after_chr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != 61)
		i++;
	if (str[i])
	{
		i++;
		ft_putstr_fd(&str[i], 1);
	}
}

void	print_export(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_put_str_until_chr(env[i]);
		if (ft_strrchr(env[i], '='))
		{
			write(1, "=", 1);
			write(1, "\"", 1);
			ft_put_str_after_chr(env[i]);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}
