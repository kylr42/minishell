#include "libft.h"

static char	*ft_reverse(char *list, int size, int n)
{
	int		i;
	char	*mal;

	i = 0;
	mal = (char *) malloc(sizeof(char) * size + 2);
	if (!mal)
		return (NULL);
	if (n < 0)
		mal[i++] = '-';
	if (n == 0)
		mal[i++] = '0';
	while (size-- > 0)
	{
		mal[i] = list[size];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	list[13];

	i = 0;
	num = (long) n;
	if (!num)
		list[i] = '0';
	else if (num < 0)
		num = -num;
	while (num > 0)
	{
		list[i++] = num % 10 + 48;
		num /= 10;
	}
	return (ft_reverse(list, i, n));
}
