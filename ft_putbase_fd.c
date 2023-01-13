/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:02:46 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/13 21:04:35 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned	int	unsigned_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	while (n != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

void	print_unsigned(unsigned int num, int fd)
{
	if (num >= 10)
	{
		print_unsigned(num / 10, fd);
	}
	ft_putchar_fd(num % 10 + '0', fd);
}

int	ft_putbase_fd(unsigned int n, int fd)
{
	int	len;

	if (n == 0)
		return (write(fd, "0", 1));
	len = unsigned_digits(n);
	print_unsigned(n, fd);
	return (len);
}
