#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (dst[x] && x < size)
		x++;
	while ((x + y + 1) < size && src[y])
	{
		dst[x + y] = src[y];
		y++;
	}
	if (x < size)
		dst[x + y] = '\0';
	return (x + ft_strlen(src));
}
