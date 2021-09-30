#include "libft.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = -1;
	if (n < 0)
		write(1, str, ft_strlen(str) + n);
	else
	{
		while (str[++i] && i < n)
			write(1, &str[i], 1);
	}

}