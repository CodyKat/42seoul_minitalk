/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:06:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/13 03:49:50 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);

static char letter;

void	signal1_handler(int signo, siginfo_t *info, void *secret)
{
	letter <<= 1;
	usleep(15);
	kill(info->si_pid, SIGUSR1);
}

void	signal2_handler(int signo, siginfo_t *info, void *secret)
{
	letter <<= 1;
	letter |= 0x1;
	usleep(15);
	kill(info->si_pid, SIGUSR1);
}


void	set_signal_action(struct sigaction *action1, struct sigaction *action2)
{
	sigemptyset(&(action1->sa_mask));
	sigemptyset(&(action2->sa_mask));
	action1->sa_flags = SA_SIGINFO;
	action2->sa_flags = SA_SIGINFO;
	action1->sa_sigaction = signal1_handler;
	action2->sa_sigaction = signal2_handler;
}

int	main()
{
	struct sigaction	action1;
	struct sigaction	action2;
	int					pid;
	int					count;

	set_signal_action(&action1, &action2);
	pid = getpid();
	ft_printf("%d\n", pid);
	letter = '\0';
	count = 0;
	while (1)
	{
		sigaction(SIGUSR1, &action1, NULL);
		sigaction(SIGUSR2, &action2, NULL);
		pause();
		count++;
		if (count == 8)
		{
			write(1, &letter, 1);
			letter = '\0';
			count = 0;
		}
	}
	return (0);
}
