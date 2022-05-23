/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:06:24 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/05/24 01:13:37 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);

static char	g_letter;

void	signal1_handler(int signo, siginfo_t *info, void *secret)
{
	secret = 0;
	g_letter <<= 1;
	usleep(30);
	kill(info->si_pid, signo);
}

void	signal2_handler(int signo, siginfo_t *info, void *secret)
{
	secret = 0;
	g_letter <<= 1;
	g_letter |= 0x1;
	usleep(30);
	kill(info->si_pid, signo);
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

int	main(void)
{
	struct sigaction	action1;
	struct sigaction	action2;
	int					pid;
	int					count;

	set_signal_action(&action1, &action2);
	pid = getpid();
	ft_printf("%d\n", pid);
	g_letter = '\0';
	count = 0;
	while (1)
	{
		sigaction(SIGUSR1, &action1, NULL);
		sigaction(SIGUSR2, &action2, NULL);
		pause();
		count++;
		if (count == 8)
		{
			write(1, &g_letter, 1);
			g_letter = '\0';
			count = 0;
		}
	}
	return (0);
}
