/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wearaujo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:50:48 by wearaujo          #+#    #+#             */
/*   Updated: 2023/01/13 21:06:02 by wearaujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *fds, ...);
void	ft_putchar_fd(char c, int fd);
int		ft_pointer_fd(unsigned long long s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_puthex_num_fd(unsigned int hex, int fd, const char p);
int		ft_putstr_fd(char *s, int fd);
int		ft_putbase_fd(unsigned int n, int fd);

#endif
