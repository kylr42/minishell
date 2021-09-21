#include "libft.h"

void	*ft_memset (void *destination, int c, size_t n)
{
	char	*dst;

	dst = (char *) destination;
	while (n > 0)
		dst[--n] = (char) c;
	return (dst);
}
