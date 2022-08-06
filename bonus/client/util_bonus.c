/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:37:21 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/01 21:17:12 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_isdigit(char letter)
{
	if ('0' <= letter && letter <= '9')
		return (1);
	else if (letter == '\0')
		return (0);
	ft_error();
	return (0);
}

int	ft_atoi(char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign *= -1;
	}
	while (ft_isdigit(*str))
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
}

void	init_message_check_error(char **message, char **end_message, \
										int argc, char **argv)
{
	int	server_pid;

	if (argc != 3)
		ft_error();
	server_pid = ft_atoi(argv[1]);
	if (100 >= server_pid || server_pid > 99999)
		ft_error();
	*message = argv[2];
	*end_message = "\nFINISH!!\n";
}
