/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:10:55 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/13 21:05:53 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_porcento(const char p, va_list args, int fd)
{
	if (p == 'c')
	{
		ft_putchar_fd(va_arg(args, int), fd);
		return (1);
	}
	else if (p == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	else if (p == 'p')
		return (ft_pointer_fd(va_arg(args, unsigned long long), fd));
	else if (p == 'd' || p == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	else if (p == 'u')
		return (ft_putbase_fd(va_arg(args, unsigned int), fd));
	else if (p == 'x' || p == 'X')
		return (ft_puthex_num_fd(va_arg(args, unsigned int), fd, p));
	else if (p == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	else
		return (ft_putstr_fd("erro", fd));
}

int	ft_printf(const char *fds, ...)
{
	int				i;
	int				len;
	va_list			args;

	va_start (args, fds);
	i = 0;
	len = 0;
	while (fds[i] != '\0')
	{
		if (fds[i] != '%')
		{
			len++;
			ft_putchar_fd(fds[i], 1);
		}
		else if (fds[i] == '%')
		{
			len += ft_porcento(fds[i + 1], args, 1);
			i++;
		}
		i++;
	}
	va_end (args);
	return (len);
}
/*
int main() 
{ 
	int x = 'p';
    ft_printf("%p\n", x); 

    return 0;
}*/
