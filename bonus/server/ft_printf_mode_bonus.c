/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mode_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 08:26:22 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/01 21:25:54 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(va_list ap)
{
	char	output;

	output = va_arg(ap, int);
	write(1, &output, 1);
	return (1);
}

int	ft_print_string(va_list ap)
{
	char	*output;
	int		len;

	output = va_arg(ap, char *);
	if (output == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(output);
	write(1, output, len);
	return (len);
}

int	ft_print_pointer(va_list ap)
{
	unsigned long	output_long;
	char			*output;
	int				len;

	output_long = va_arg(ap, unsigned long);
	output = ft_longto_other_base(output_long, "0123456789abcdef");
	if (output == 0)
		return (0);
	len = ft_strlen(output);
	write(1, "0x", 2);
	write(1, output, len);
	free(output);
	return (len + 2);
}

int	ft_print_decimal(va_list ap)
{
	int		output_int;
	int		len;
	char	*output;

	output_int = va_arg(ap, int);
	output = ft_itoa(output_int);
	if (output == 0)
		return (0);
	len = ft_strlen(output);
	write(1, output, len);
	free(output);
	return (len);
}

int	ft_print_uibase(va_list ap, char type)
{
	unsigned int	output_ui;
	char			*output;
	int				len;

	output_ui = va_arg(ap, unsigned int);
	if (type == 'x')
		output = ft_uito_other_base(output_ui, "0123456789abcdef");
	else if (type == 'X')
		output = ft_uito_other_base(output_ui, "0123456789ABCDEF");
	else
		output = ft_uito_other_base(output_ui, "0123456789");
	if (output == 0)
		return (0);
	len = ft_strlen(output);
	write(1, output, len);
	free(output);
	return (len);
}
