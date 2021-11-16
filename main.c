/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 07:15:36 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 07:15:39 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_shell	shell;
	int		rl_catch_signals;

	if (argc > 1)
		printf(MAG"Hello, %s! %s loading...\n"RESET, getenv("USER"), argv[0]);
	ft_putstr_fd(MAG"\n"
		 "      _/_/_/  _/    _/  _/_/_/_/  _/        _/     \n"
		 "   _/        _/    _/  _/        _/        _/      \n"
		 "    _/_/    _/_/_/_/  _/_/_/    _/        _/       \n"
		 "       _/  _/    _/  _/        _/        _/        \n"
		 "_/_/_/    _/    _/  _/_/_/_/  _/_/_/_/  _/_/_/_/   \n"
		 "\n"RESET, 2);
	rl_catch_signals = 0;
	rl_set_signals();
	ft_init(&shell, envp);
	ft_signal_main();
	ft_loop(&shell);
	return (0);
}
