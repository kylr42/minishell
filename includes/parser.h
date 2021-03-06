/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:12:43 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 07:13:39 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "includes.h"

int		ft_loop(t_shell *shell);
int		ft_skip_gap(const char *str);
int		ft_parser(t_shell *shell, char *str);
int		ft_get_redirects(t_cmd *cmd, bool is_fork);

void	ft_init_ps(t_shell *shell);
void	ft_init(t_shell *shell, char *envp[]);

char	*ft_get_key(bool digit, char *s, size_t *i);
char	*ft_get_el_env(t_shell *shell, const char *key);
char	*ft_parser_dollar(t_shell *shell, const char *s, size_t *i);

#endif //PARSER_H
