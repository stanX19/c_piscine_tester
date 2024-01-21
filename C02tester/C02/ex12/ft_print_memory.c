/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:23:46 by shatan            #+#    #+#             */
/*   Updated: 2024/01/21 15:25:23 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned long long nb, int len)
{
	int	temp;

	if (len > 1)
		ft_puthex(nb / 16, len - 1);
	temp = nb % 16;
	if (temp < 10)
		temp = temp + '0';
	else
		temp = temp + 'a' - 10;
	write(1, &temp, 1);
}

void	ft_printhex(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_puthex((unsigned char)str[i], 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		++i;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		++i;
	}
}

int	ft_printreadable(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] < 32 || str[i] >= 127)
			write(1, ".", 1);
		else
			write(1, str + i, 1);
		++i;
	}
	return (1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				len;

	i = 0;
	while (i < size)
	{
		if (i + 16 < size)
			len = 16;
		else
			len = size - i;
		ft_puthex((unsigned long long)addr + i, 16);
		write(1, ": ", 2);
		ft_printhex((char *)addr + i, len);
		ft_printreadable((char *)addr + i, len);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
/*
int	main(void)
{
	char str[3000] = "abcdefghijklmnopqrstu\41vwxlyz|";
	ft_print_memory(str, 300);
	return (0);
}
*/
