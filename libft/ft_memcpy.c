/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:16:51 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:16:53 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
