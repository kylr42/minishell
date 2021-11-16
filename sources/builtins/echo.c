/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:07:11 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:07:12 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **str)
{
	int		i;
	bool	display_return;

	i = 0;
	display_return = true;
	if (!str || !*(++str))
		return ((int) write(1, "\n", 1));
	else if (!ft_strncmp(*str, "-n", 100))
		display_return = false;
	else
		--i;
	while (str[++i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			write(1, " ", 1);
		else if (display_return)
			ft_putchar_fd('\n', 1);
	}
	return (0);
}
