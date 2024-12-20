/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:38 by katakada          #+#    #+#             */
/*   Updated: 2024/12/12 15:17:53 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_client_pid;

static void	init_bit_count(int *bit_count, unsigned char *utf8_char)
{
	*bit_count = 0;
	utf8_char[0] = 0;
	utf8_char[1] = 0;
	utf8_char[2] = 0;
	utf8_char[3] = 0;
}

static int	get_bit_size(unsigned char *utf8_char)
{
	if ((utf8_char[0] & 0xF0) == 0xF0)
		return (32);
	else if ((utf8_char[0] & 0xE0) == 0xE0)
		return (24);
	else if ((utf8_char[0] & 0xC0) == 0xC0)
		return (16);
	else
		return (8);
}

static void	sig_opelation(int signum, unsigned char *utf8_char, int *bit_count)
{
	int	utf_index;

	utf_index = *bit_count / 8;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		utf8_char[utf_index] <<= 1;
		(*bit_count)++;
	}
	if (signum == SIGUSR2)
		utf8_char[utf_index] += 1;
}

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	utf8_char[5];
	static int				bit_count;
	int						bit_size;
	int						i;

	(void)context;
	if (g_client_pid != siginfo->si_pid && siginfo->si_pid != 0)
		init_bit_count(&bit_count, utf8_char);
	sig_opelation(signum, utf8_char, &bit_count);
	bit_size = get_bit_size(utf8_char);
	if (bit_count == bit_size)
	{
		i = 0;
		while (utf8_char[i] != '\0')
			write(STDOUT_FILENO, &utf8_char[i++], 1);
		init_bit_count(&bit_count, utf8_char);
	}
	if (siginfo->si_pid != 0)
		g_client_pid = siginfo->si_pid;
	if (send_kill_signal(g_client_pid, SIGUSR1) == -1)
		init_bit_count(&bit_count, utf8_char);
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
		error_exit("Error: failed to set signal handler\n", NULL);
	if (sigaction(SIGUSR2, &s_action, NULL) == -1)
		error_exit("Error: failed to set signal handler\n", NULL);
	while (1)
		pause();
	return (0);
}
