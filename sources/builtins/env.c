/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:07:20 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:07:21 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_shell *shell)
{
	t_list	*tmp;

	tmp = shell->env;
	while (tmp->next)
	{
		if (ft_strrchr(tmp->content, '='))
			ft_putendl_fd(tmp->content, 1);
		tmp = tmp->next;
	}
	if (ft_strrchr(tmp->content, '='))
		ft_putendl_fd(tmp->content, 1);
	return (0);
}
