/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:23:13 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 07:23:15 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_keylen(const char *keyval)
{
	size_t	i;

	i = 0;
	while (keyval[i] && keyval[i] != '=')
		i++;
	return (i);
}

char	*ft_get_val_env(const char *keyval)
{
	size_t	len_key;

	if (!keyval)
		return (ft_strdup(""));
	len_key = ft_keylen(keyval);
	if (len_key && keyval[len_key] == '=')
		return (ft_strdup(keyval + ft_keylen(keyval) + 1));
	else
		return (ft_strdup(""));
}

char	*ft_get_el_env(t_shell *shell, const char *key)
{
	t_list	*res;

	res = ft_lstfind(shell->env, key);
	if (res)
		return (ft_get_val_env(res->content));
	else
		return (ft_strdup(""));
}

void	ft_delete_el_env(t_shell *shell, const char *key)
{
	t_list	*res;

	res = ft_lstpop_find(&shell->env, key);
	if (res)
	{
		ft_split_free(shell->arr_env);
		ft_lstclear(&res, free);
		shell->arr_env = ft_lst_to_array(shell->env);
	}
}

void	ft_update_el_env(t_shell *shell, const char *keyval)
{
	ft_delete_el_env(shell, keyval);
	ft_lstadd_front(&shell->env, ft_lstnew(ft_strdup(keyval)));
	ft_split_free(shell->arr_env);
	shell->arr_env = ft_lst_to_array(shell->env);
}
