/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:38 by katakada          #+#    #+#             */
/*   Updated: 2024/12/11 03:01:58 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_client_pid;

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	utf8_char[4];
	int						utf_index;
	static int				bit_count;
	int						bit_size;
	int						i;

	(void)context;
	if (g_client_pid != siginfo->si_pid && siginfo->si_pid != 0)
	{
		if (g_client_pid != 0)
			kill(siginfo->si_pid, SIGUSR2);
		bit_count = 0;
		utf8_char[0] = 0;
		utf8_char[1] = 0;
		utf8_char[2] = 0;
		utf8_char[3] = 0;
	}
	utf_index = bit_count / 8;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		utf8_char[utf_index] <<= 1;
		bit_count++;
	}
	if (signum == SIGUSR2)
		utf8_char[utf_index] += 1;
	if ((utf8_char[0] & 0xF0) == 0xF0)
		bit_size = 32;
	else if ((utf8_char[0] & 0xE0) == 0xE0)
		bit_size = 24;
	else if ((utf8_char[0] & 0xC0) == 0xC0)
		bit_size = 16;
	else
		bit_size = 8;
	if (bit_count == bit_size)
	{
		i = 0;
		while (utf8_char[i] != '\0')
		{
			write(STDOUT_FILENO, &utf8_char[i], 1);
			i++;
		}
		bit_count = 0;
		utf8_char[0] = 0;
		utf8_char[1] = 0;
		utf8_char[2] = 0;
		utf8_char[3] = 0;
	}
	usleep(100);
	if (siginfo->si_pid != 0)
		g_client_pid = siginfo->si_pid;
	kill(g_client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("SERVER PID: %d\n", getpid());
	s_action.sa_sigaction = sig_handler;
	sigemptyset(&s_action.sa_mask);
	sigaddset(&s_action.sa_mask, SIGUSR1);
	sigaddset(&s_action.sa_mask, SIGUSR2);
	s_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &s_action, NULL) == -1)
		exit(1);
	while (1)
		pause();
	return (0);
}
