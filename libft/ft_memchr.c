/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:16:31 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:16:32 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	i = 0;
	ch = (unsigned char)c;
	str = (unsigned char *)arr;
	while (n--)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
