#include "minishell.h"

static void		echo_out(char **str, int pos)
{
	size_t	str_len;
	t_bool	ends_with;
	t_bool	starts_with;

	str_len = (int)ft_strlen(str[pos]);
	starts_with = str[pos][0] == '"' || str[pos][0] == '\'';
	ends_with = str[pos][str_len - 1] == '"' || str[pos][str_len - 1] == '\'';
	if (ends_with && starts_with)
		ft_putnstr(str[pos] + 1, -1);
	else if (ends_with)
		ft_putnstr(str[pos], -1);
	else if (starts_with)
		ft_putstr_fd(str[pos] + 1, 1);
	else
		ft_putstr_fd(str[pos], 1);
	if (str[pos + 1])
		ft_putchar_fd(' ', 1);
}

int		echo(char **str)
{
	int i;
	t_bool display_return;

	i = 0;
	display_return = true;
	if (!str[0])
		return write(1, "\n", 1);
	else if (!ft_strncmp(str[0], "-n", 100))
		display_return = false;
	else
		--i;
	while (str[++i])
	{
		echo_out(str, i);
		if (str[i + 1])
			ft_putchar_fd(' ', 1);
		else if (!display_return)
			ft_putchar_fd('\n', 1);
	}
	return (0);
}