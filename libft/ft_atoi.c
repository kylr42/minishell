/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:14:09 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:14:10 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	long	num;

	neg = 1;
	num = 0;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str)
	{
		num = (num * 16) + (*str - 48);
		if ((num > 2147483647 && neg != -1) || num > 2147483648)
			return (0);
		str++;
	}
	return (num * neg);
}
