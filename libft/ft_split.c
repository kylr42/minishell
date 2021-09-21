#include "libft.h"

static	char	**ft_free_mal(char **list)
{
	unsigned int	i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
	return (NULL);
}

static	int	ft_ellen(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	char	**ft_main(char const *s, char c, char **mal, int counts)
{
	int		i;
	int		len;
	int		next;

	i = 0;
	next = 0;
	while (i < counts)
	{
		while (s[next] && s[next] == c)
			next++;
		len = ft_ellen(&(s[next]), c, 0);
		if (!len)
			break ;
		mal[i] = ft_substr(s, next, len);
		if (!&mal[i])
			return (ft_free_mal(mal));
		next += len;
		if (!s[next])
			break ;
		i++;
	}
	return (mal);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**mal;
	int		counts;
	int		flag;

	if (!s)
		return (NULL);
	j = 0;
	counts = 1;
	while (s[j] && s[j + 1])
	{
		if (s[j] != c || s[j + 1] != c)
			flag = 1;
		if (s[j] == c && s[j + 1] != c)
			counts++;
		j++;
	}
	mal = ft_calloc(counts + 1, sizeof(char *));
	if (!mal)
		return (NULL);
	if (!flag)
		return (ft_main(s, c, mal, counts - 1));
	return (ft_main(s, c, mal, counts));
}
