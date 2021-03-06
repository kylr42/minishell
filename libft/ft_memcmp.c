/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:16:41 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:16:42 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*b1;
	unsigned char	*b2;
	size_t			i;

	i = -1;
	b1 = (unsigned char *) s1;
	b2 = (unsigned char *) s2;
	if (b1 == NULL && b2 == NULL)
		return (0);
	while (++i < n)
		if (b1[i] != b2[i])
			return (b1[i] - b2[i]);
	return (0);
}
