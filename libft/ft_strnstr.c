/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:20:36 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:20:38 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		j;
	size_t	i;

	i = 0;
	if (!(needle[i]))
		return ((char *)(haystack));
	while (i < len && haystack[i])
	{
		j = 0;
		while (needle[j])
		{
			if (needle[j] != haystack[i + j])
				break ;
			j++;
		}
		if (needle[j] == '\0' && (i + j <= len))
			return ((char *) &(haystack[i]));
		i++;
	}
	return (NULL);
}
