/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:38:37 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/24 01:17:59 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define FLAG 0x80

int		ft_atoi(char *str);
void	check_error(int argc, int server_pid);

void	signal1_handler(int signo)
{
	static int	bit_count = 0;

	signo = 0;
	bit_count++;
	if (bit_count == 8)
	{
		bit_count = 0;
		usleep(100);
	}
}

void	processing(int server_pid, char sending_letter)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count++ < 8)
	{
		if ((sending_letter & FLAG) != FLAG)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		signal(SIGUSR1, signal1_handler);
		signal(SIGUSR2, signal1_handler);
		pause();
		usleep(35);
		sending_letter <<= 1;
	}
	write(1, &sending_letter, 1);
}

void	print_log(char sending_letter)
{
	static int	utf_count = 0;
	static char	utf_arr[4];
	int			offset;

	offset = 0;
	if ((sending_letter & FLAG) == 0)
	{
		if (utf_count > 0)
		{
			write(1, "[ ", 2);
			while (offset < utf_count)
				write(1, &utf_arr[offset++], 1);
			write(1, " send OK ]\n", 11);
			utf_count = 0;
		}
		write(1, "[ ", 2);
		write(1, &sending_letter, 1);
		write(1, " send OK ]\n", 11);
	}
	else
	{
		utf_arr[utf_count] = sending_letter;
		utf_count++;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*message;
	char	sending_letter;
	char	*end_message;

	end_message = "FINISH!!";
	server_pid = ft_atoi(argv[1]);
	check_error(argc, server_pid);
	message = argv[2];
	while (*message)
	{
		sending_letter = *message;
		processing(server_pid, sending_letter);
		print_log(sending_letter);
		message++;
	}
	while (*end_message)
	{
		sending_letter = *end_message;
		processing(server_pid, sending_letter);
		print_log(sending_letter);
		end_message++;
	}
	return (0);
}
