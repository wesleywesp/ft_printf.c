/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_num_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:09:18 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/13 21:04:45 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex_digits(unsigned int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

void	ft_tranform_hex(unsigned int num, int fd, const char format)
{
	if (num >= 16)
	{
		ft_tranform_hex(num / 16, fd, format);
		ft_tranform_hex(num % 16, fd, format);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), fd);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 97), fd);
			else if (format == 'X')
				ft_putchar_fd((num - 10 + 65), fd);
		}
	}
}

int	ft_puthex_num_fd(unsigned int hex, int fd, const char p)
{
	if (hex == 0)
	{
		return (write(fd, "0", 1));
	}
	else
		ft_tranform_hex(hex, fd, p);
	return (count_hex_digits(hex));
}
