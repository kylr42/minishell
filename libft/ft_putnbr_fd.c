/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiona <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 08:17:48 by jsiona            #+#    #+#             */
/*   Updated: 2021/11/16 08:17:49 by jsiona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	num;
	char	list[2048];

	i = 0;
	num = (long) n;
	if (!n)
		ft_putchar_fd('0', fd);
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	while (num > 0)
	{
		list[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i-- > 0)
		ft_putchar_fd(list[i], fd);
}
