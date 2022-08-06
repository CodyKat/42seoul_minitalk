/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:33:44 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/01 21:15:57 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_print_char(va_list ap);
int		ft_print_string(va_list ap);
int		ft_print_pointer(va_list ap);
int		ft_print_decimal(va_list ap);
int		ft_print_uibase(va_list ap, char type);
int		ft_cal_output_len(unsigned long dec, int base_len);
char	*ft_uito_other_base(unsigned int dec, char *base);
char	*ft_longto_other_base(unsigned long dec, char *base);

#endif
