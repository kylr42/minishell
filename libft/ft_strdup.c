#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (NULL);
	while (++i < len)
		tmp[i] = s1[i];
	tmp[i] = '\0';
	return (tmp);
}
