/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:00 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/13 21:04:23 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long long s)
{
	int	count;

	count = 0;
	while (s != 0)
	{
		count++;
		s /= 16;
	}
	return (count);
}

void	ft_hex_ptr(unsigned long long s, int fd)
{
	if (s >= 16)
	{
		ft_hex_ptr(s / 16, fd);
		ft_hex_ptr(s % 16, fd);
	}
	else
	{
		if (s <= 9)
			ft_putchar_fd((s + 48), fd);
		else
			ft_putchar_fd((s - 10 + 'a'), fd);
	}
}

int	ft_pointer_fd(unsigned long long s, int fd)
{
	if (s == 0)
		return (write (fd, "(nil)", 5));
	write(fd, "0x", 2);
	ft_hex_ptr(s, fd);
	return (count_hex(s) + 2);
}
