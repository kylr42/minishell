#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t count)
{
	char	*dst;
	char	*src;

	dst = (char *) dest;
	src = (char *) source;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (count-- > 0)
		dst[count] = src[count];
	return (dest);
}
