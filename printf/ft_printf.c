/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:13:09 by onoras            #+#    #+#             */
/*   Updated: 2025/11/04 10:31:34 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int	ft_check_format(char f, va_list arg)
{
	int	count;

	count = 0;
	if (f == 'c' || f == '%' || f == 's')
		count = ft_printer_chars(f, arg);
	if (f == 'p')
		count = ft_convert_p(arg);
	if (f == 'd' || f == 'i')
		count = ft_printer_nbrs(arg);
	if (f == 'x')
		count = ft_convert_hex(arg, 0);
	if (f == 'X')
		count = ft_convert_hex(arg, 1);
	if (f == 'u')
		count = ft_printer_unbrs(arg);
	return (count);
}

int	ft_printer_chars(char type, va_list args)
{
	char	*str;
	int		len;

	if (type == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (type == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
		return (len);
	}
	if (type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printer_nbrs(va_list args)
{
	long	n;
	int		count;

	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	count = ft_counter(n);
	if (n < 0)
		return (count + 1);
	return (count);
}

int	ft_counter(long nbr)
{
	int	digits;

	digits = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		digits++;
		nbr /= 10;
	}
	return (digits);
}

int	ft_printf(const char *f, ...)
{
	int			count;
	const char	*format;
	va_list		args;

	count = 0;
	va_start(args, f);
	format = f;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		else
		{
			count += ft_check_format(*(++format), args);
		}
		format++;
	}
	return (count);
}
