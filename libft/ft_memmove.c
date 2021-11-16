/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:16:59 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:17:00 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = -1;
	dst = (unsigned char *) destination;
	src = (unsigned char *) source;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
		while (n-- > 0)
			dst[n] = src[n];
	else
		while (++i < n)
			dst[i] = src[i];
	return (dst);
}
