/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:18 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/01 21:16:32 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_write_char(const char *chr)
{
	write(1, chr, 1);
	return (1);
}

int	ft_matched_format(va_list ap, const char *cursor)
{
	if (*cursor == 'c')
		return (ft_print_char(ap));
	else if (*cursor == 's')
		return (ft_print_string(ap));
	else if (*cursor == 'p')
		return (ft_print_pointer(ap));
	else if (*cursor == 'd' || *cursor == 'i')
		return (ft_print_decimal(ap));
	else if (*cursor == 'x' || *cursor == 'X' || *cursor == 'u')
		return (ft_print_uibase(ap, *cursor));
	else
		return (ft_write_char("%"));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			print_len;
	const char	*format_cursor;

	print_len = 0;
	format_cursor = format;
	va_start(ap, format);
	while (*format_cursor != 0)
	{
		if (*format_cursor == '%')
		{
			print_len += ft_matched_format(ap, format_cursor + 1);
			format_cursor += 2;
		}
		else
		{
			print_len += ft_write_char(format_cursor);
			format_cursor++;
		}
	}
	va_end(ap);
	return (print_len);
}
