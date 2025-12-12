/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:15:15 by onoras            #+#    #+#             */
/*   Updated: 2025/11/04 10:33:22 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int	ft_convert_hex(va_list args, int hexcase)
{
	unsigned int	result;
	char			*hex_digits;
	char			buffer[32];
	int				i;

	result = va_arg(args, long);
	if (hexcase)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	i = 0;
	if (result == 0)
		buffer[i++] = '0';
	while (result > 0)
	{
		buffer[i++] = hex_digits[result % 16];
		result /= 16;
	}
	result = i;
	while (i--)
		write(1, &buffer[i], 1);
	return (result);
}

int	ft_convert_hex_pointer(void *ptr)
{
	unsigned long	result;
	char			*hex_digits;
	char			buffer[32];
	int				i;

	hex_digits = "0123456789abcdef";
	result = (unsigned long)ptr;
	i = 0;
	if (result == 0)
		buffer[i++] = '0';
	while (result > 0)
	{
		buffer[i++] = hex_digits[result % 16];
		result /= 16;
	}
	result = i;
	while (i--)
		write(1, &buffer[i], 1);
	return (result);
}

int	ft_convert_p(va_list args)
{
	int		result;
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	result = ft_convert_hex_pointer(ptr);
	return (result + 2);
}

int	ft_printer_unbrs(va_list args)
{
	unsigned int	unn;
	int				count;

	unn = va_arg(args, int);
	ft_putnbr_unsigned(unn);
	count = ft_counter(unn);
	if (unn < 0)
		return (count + 1);
	return (count);
}

void	ft_putnbr_unsigned(unsigned int n)
{
	char			c;
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
		ft_putnbr_unsigned(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}
