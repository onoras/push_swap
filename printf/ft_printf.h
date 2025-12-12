/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onoras <onoras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:38:09 by onoras            #+#    #+#             */
/*   Updated: 2025/12/12 11:17:54 by onoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *f, ...);
int		ft_check_format(char f, va_list arg);
int		ft_printer_nbrs(va_list args);
int		ft_printer_unbrs(va_list args);
int		ft_printer_chars(char type, va_list args);
int		ft_counter(long nbr);
int		ft_convert_hex(va_list args, int hexcase);
int		ft_convert_hex_pointer(void *ptr);
int		ft_convert_p(va_list args);
void	ft_putnbr_unsigned(unsigned int n);

#endif
