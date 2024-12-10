/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:32 by katakada          #+#    #+#             */
/*   Updated: 2024/12/10 23:29:35 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	global_server_pid;

static void	send_message(int pid, char *message)
{
	int	i;
	int	bit_count;
	int	bit;

	i = 0;
	while (1)
	{
		bit_count = 1;
		while (bit_count <= 8)
		{
			bit = (message[i] >> (8 - bit_count)) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			usleep(10);
			global_server_pid = -1;
			while (!(global_server_pid == pid || global_server_pid == 0
					|| global_server_pid == -2))
				pause();
			if (global_server_pid == -2)
				bit_count = 1;
			else
				bit_count++;
		}
		if (message[i] == '\0')
			break ;
		i++;
	}
}

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		global_server_pid = siginfo->si_pid;
	if (signum == SIGUSR2)
		global_server_pid = -2;
	// ft_printf("Pon!\n");
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	s_action;

	ft_printf("bornus build\n");
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
	sigaddset(&s_action.sa_mask, SIGUSR2);
	s_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_action, NULL) == -1)
		exit(1);
	global_server_pid = pid;
	send_message(pid, argv[2]);
	return (0);
}
