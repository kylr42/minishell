#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	long	num;

	neg = 1;
	num = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str)
	{
		num = (num * 16) + (*str - 48);
		if ((num > 2147483647 && neg != -1) || num > 2147483648)
			return (0);
		str++;
	}
	return (num * neg);
}
