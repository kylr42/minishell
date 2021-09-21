#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	unsigned char	*dst;
	unsigned char	*src;
	size_t			i;

	i = 0;
	dst = (unsigned char *) dest;
	src = (unsigned char *) source;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < count)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char) ch)
			return ((void *) dest + i + 1);
		i++;
	}
	return (NULL);
}
