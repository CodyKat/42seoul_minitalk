/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:38:37 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/02 16:33:29 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

#define MASK 0b10000000

int		ft_atoi(char *str);
void	ft_error(void);
void	init_message_check_error(char **message, char **end_message, \
										int argc, char **argv);

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

void	send_one_byte(int server_pid, char sending_letter)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count++ < 8)
	{
		if ((sending_letter & MASK) != MASK)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_error();
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_error();
		}
		pause();
		usleep(50);
		sending_letter <<= 1;
	}
}

void	print_one_byte(char sending_letter)
{
	char	*string_new_line;

	write(1, "[ ", 2);
	if (sending_letter == '\n')
	{
		string_new_line = "NEW_LINE";
		while (*string_new_line)
		{
			write(1, string_new_line, 1);
			string_new_line++;
		}
	}
	else
		write(1, &sending_letter, 1);
	write(1, " send OK ]\n", 11);
}

void	print_log(char sending_letter)
{
	static int	utf_count = 0;
	static char	utf_arr[4];
	int			offset;

	offset = 0;
	if ((sending_letter & MASK) == 0)
	{
		if (utf_count > 0)
		{
			write(1, "[ ", 2);
			while (offset < utf_count)
				write(1, &utf_arr[offset++], 1);
			write(1, " send OK ]\n", 11);
			utf_count = 0;
		}
		else
			print_one_byte(sending_letter);
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

	signal(SIGUSR1, signal1_handler);
	signal(SIGUSR2, signal1_handler);
	init_message_check_error(&message, &end_message, argc, argv);
	server_pid = ft_atoi(argv[1]);
	while (*message)
	{
		sending_letter = *message;
		send_one_byte(server_pid, sending_letter);
		print_log(sending_letter);
		message++;
	}
	while (*end_message)
	{
		sending_letter = *end_message;
		send_one_byte(server_pid, sending_letter);
		print_log(sending_letter);
		end_message++;
	}
	return (0);
}
