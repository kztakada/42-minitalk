/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 20:43:44 by katakada          #+#    #+#             */
/*   Updated: 2024/12/08 22:48:06 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	{
		ft_printf("Error: Argments are invalid (Usage: %s [PID] [MESSAGE])\n",
			argv[0]);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 4194304)
	{
		ft_printf("Error: %s is invalid PID (Available PID: 100~4194304)\n",
			argv[1]);
		exit(1);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_printf("Error: Message is empty\n");
		exit(1);
	}
	send_message(pid, argv[2]);
	return (0);
}
