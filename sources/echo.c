#include "minishell.h"

int		echo(char **str)
{
	int i;
	t_bool display_return;

	i = 0;
	display_return = true;
	if (!str || !*str)
		return write(1, "\n", 1);
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
