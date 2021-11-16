/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:16:26 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:16:27 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
