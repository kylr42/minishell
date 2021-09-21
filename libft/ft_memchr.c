#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char *)arr;
	while (n--)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
