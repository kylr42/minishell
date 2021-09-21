#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)(s + i));
	if (!c && !s[i])
		return ((char *)(s + i));
	return (NULL);
}
