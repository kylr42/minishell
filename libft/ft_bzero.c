#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = (char *) s;
	while (n > 0)
		c[--n] = '\0';
}
