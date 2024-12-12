/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:32 by katakada          #+#    #+#             */
/*   Updated: 2024/12/12 15:17:38 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_server_pid;

static void	weit_server_respond(void)
{
	int	time_count;

	time_count = 0;
	while (g_server_pid < 0)
	{
		usleep(100);
		time_count++;
		if (time_count > 100)
			error_exit("Error: Server is not responding\n", NULL);
	}
}

static void	bit_8_opelation(int pid, char msg_char)
{
	int	bit_count;
	int	bit;

	bit_count = 1;
	while (bit_count <= 8)
	{
		weit_server_respond();
		g_server_pid *= -1;
		bit = (msg_char >> (8 - bit_count)) & 1;
		if (bit == 0)
			if (send_kill_signal(pid, SIGUSR1) == -1)
				error_exit("Error: Server is not responding. Is PID sure?\n",
					NULL);
		if (bit == 1)
			if (send_kill_signal(pid, SIGUSR2) == -1)
				error_exit("Error: Server is not responding. Is PID sure?\n",
					NULL);
		bit_count++;
	}
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	g_server_pid = pid;
	while (1)
	{
		bit_8_opelation(pid, message[i]);
		if (message[i] == '\0')
			break ;
		i++;
	}
}

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	if ((siginfo->si_pid == (g_server_pid * -1) || siginfo->si_pid == 0)
		&& signum == SIGUSR1)
		g_server_pid *= -1;
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	s_action;

	if (argc != 3)
		error_exit("Error: Invalid Argments (Usage: %s [PID] [MESSAGE])\n",
			argv[0]);
	if (!is_int_str(argv[1]))
		error_exit("Error: %s is invalid PID (Available PID: 2~4194304)\n",
			argv[1]);
	pid = ft_atoi(argv[1]);
	if (pid <= 1 || pid > 4194304)
		error_exit("Error: %s is invalid PID (Available PID: 2~4194304)\n",
			argv[1]);
	if (ft_strlen(argv[2]) == 0)
		error_exit("Error: Message is empty\n", NULL);
	s_action.sa_sigaction = sig_handler;
	sigemptyset(&s_action.sa_mask);
	sigaddset(&s_action.sa_mask, SIGUSR1);
	s_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1)
		error_exit("Error: failed to set signal handler\n", NULL);
	send_message(pid, argv[2]);
	return (0);
}
