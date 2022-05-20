/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msukri <msukri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:01:27 by msukri            #+#    #+#             */
/*   Updated: 2022/05/20 16:53:55 by msukri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

static void	string_count(int signal)
{
	static int	count = 0;

	if (signal == SIGUSR1)
		++count;
	else if (signal == SIGUSR2)
	{
		ft_putnbr_fd(count, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

int	handle_bit(int server_pid, char c)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(server_pid, SIGUSR2) == -1)
				exit(0);
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
				exit(0);
		}
		bit >>= 1;
		usleep(300);
	}
	return (1);
}

int	send_str_to_server(char *str, int server_pid)
{
	char			c;

	while (*str)
	{
		c = *str++;
		handle_bit(server_pid, c);
	}
	handle_bit(server_pid, '\0');
	return (1);
}

int	main(int argc, char **argv)
{
	//struct sigaction	b_sigaction;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_putstr_fd("Sent		: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("Received	: ", 1);
	//b_sigaction.sa_handler = &string_count;
	signal(SIGUSR1, string_count);
	signal(SIGUSR2, string_count);
	send_str_to_server(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
