/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:38 by katakada          #+#    #+#             */
/*   Updated: 2024/12/10 22:58:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	global_client_pid;

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	static unsigned char	utf8_char;
	static int				bit_count;

	(void)context;
	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		utf8_char <<= 1;
		bit_count++;
	}
	if (signum == SIGUSR2)
		utf8_char += 1;
	if (bit_count == 8)
	{
		if (utf8_char != '\0')
			write(STDOUT_FILENO, &utf8_char, 1);
		bit_count = 0;
		utf8_char = 0;
	}
	usleep(10);
	if (siginfo->si_pid != 0)
		global_client_pid = siginfo->si_pid;
	kill(global_client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	s_action;

	ft_printf("bornus build\n");
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
