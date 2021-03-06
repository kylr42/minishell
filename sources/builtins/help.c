/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:56:14 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:56:23 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_put_taebag(void)
{
	ft_putendl_fd(SIL"            .------.____\n"
		  "         .-'       \\ ___)\n"
		  "      .-'         \\\\\\\n"
		  "   .-'        ___  \\\\)\n"
		  ".-'          /  (\\  |)\n"
		  "         __  \\  ( | |\n"
		  "        /  \\  \\__'| |\n"
		  "       /    \\____).-'\n"
		  "     .'       /   |\n"
		  "    /     .  /    |\n"
		  "  .'     / \\/     |\n"
		  " /      /   \\     |\n"
		  "       /    /    _|_\n"
		  "       \\   /    /\\ /\\\n"
		  "        \\ /    /__v__\\\n"
		  "         '    |       |\n"
		  "              |     .#|\n"
		  "              |#.  .##|\n"
		  "              |#######|\n"
		  "              |#######|", 1);
}

static void	ft_put_tea(void)
{
	ft_putendl_fd("                      (\n"
		  "                        )     (\n"
		  "                 ___...(-------)-....___\n"
		  "             .-\"\"       )    (          \"\"-.\n"
		  "       .-'``'|-._             )         _.-|\n"
		  "      /  .--.|   `\"\"---...........---\"\"`   |\n"
		  "     /  /    |                             |\n"
		  "     |  |    |                             |\n"
		  "      \\  \\   |                             |\n"
		  "       `\\ `\\ |                             |\n"
		  "         `\\ `|                             |\n"
		  "         _/ /\\                             /\n"
		  "        (__/  \\                           /\n"
		  "     _..---\"\"` \\                         /`\"\"---.._\n"
		  "  .-'           \\                       /          '-.\n"
		  " :               `-.__             __.-'              :\n"
		  " :                  ) \"\"---...---\"\" (                 :\n"
		  "  '._               `\"--...___...--\"`              _.'\n"
		  "jgs \\\"\"--..__                              __..--\"\"/\n"
		  "     '._     \"\"\"----.....______.....----\"\"\"     _.'\n"
		  "        `\"\"--..,,_____            _____,,..--\"\"`\n"
		  "                      `\"\"\"----\"\"\"`", 1);
}

int	ft_help(t_shell *shell, int i)
{
	ft_put_taebag();
	ft_put_tea();
	write(1, "List of built-in functions:\n", 28);
	while (shell->buil_cmd[++i])
	{
		ft_putstr_fd("- ", 1);
		ft_putendl_fd(shell->buil_cmd[i], 1);
	}
	ft_putstr_fd(RESET, 1);
	return (1);
}
