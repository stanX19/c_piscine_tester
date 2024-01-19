/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:21:59 by shatan            #+#    #+#             */
/*   Updated: 2024/01/19 13:27:15 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthex(unsigned long long nb)
{
	int	temp;

	if (nb >= 16)
		ft_puthex(nb / 16);
	temp = nb % 16;
	if (temp < 10)
		temp += '0';
	else
		temp = temp - 10 + 'a';
	write(1, &temp, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	c;

	while (*str != 0)
	{
		c = *str;
		if ((c < 32) || (c >= 127))
		{
			write(1, "\\", 1);
			if (c < 16)
				write(1, "0", 1);
			ft_puthex(c);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
