/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:32 by katakada          #+#    #+#             */
/*   Updated: 2024/12/11 00:56:29 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	is_server_ok_global;

static void	send_message(int pid, char *message)
{
	int	i;
	int	bit_count;
	int	bit;

	i = 0;
	is_server_ok_global = 1;
	while (1)
	{
		bit_count = 1;
		while (bit_count <= 8)
		{
			while (is_server_ok_global == -1)
				pause();
			if (is_server_ok_global == 0)
				exit(1);
			is_server_ok_global = -1;
			usleep(10);
			bit = (message[i] >> (8 - bit_count)) & 1;
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			bit_count++;
		}
		if (message[i] == '\0')
			break ;
		i++;
	}
}

static void	sig_handler(int signum, siginfo_t *siginfo, void *context)
{
	// static int	i = 0;
	(void)context;
	(void)siginfo;
	// ft_printf("Ping %d\n", i++);
	// ft_printf("siginfo->si_pid: %d\n", siginfo->si_pid);
	// ft_printf("signum: %d\n", signum);
	if (signum == SIGUSR1)
		is_server_ok_global = 1;
	if (signum == SIGUSR2)
		is_server_ok_global = 0;
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
	if (sigaction(SIGUSR2, &s_action, NULL) == -1)
		exit(1);
	send_message(pid, argv[2]);
	return (0);
}
