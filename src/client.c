/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:44 by katakada          #+#    #+#             */
/*   Updated: 2024/12/10 20:39:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(char *format, char *message)
{
	if (message == NULL)
		ft_printf(format);
	else
		ft_printf(format, message);
	exit(1);
}

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
			bit_count++;
			usleep(U_SLEEP_TIME);
		}
		if (message[i] == '\0')
			break ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

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
	send_message(pid, argv[2]);
	return (0);
}
