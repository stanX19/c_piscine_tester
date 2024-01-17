/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:22:23 by stan              #+#    #+#             */
/*   Updated: 2024/01/17 14:16:22 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	init(char *cb);

void	extension(char *cb)
{
	cb[3] = cb[0];
	cb[4] = cb[1] + 1;
	while (cb[3] <= '9')
	{
		while (cb[4] <= '9')
		{
			write(1, cb, 5);
			if (!(cb[0] == '9' && cb[1] == '8'))
				write(1, ", ", 2);
			cb[4]++;
		}
		cb[4] = '0';
		cb[3]++;
	}
	cb[1]++;
}

void	ft_print_comb2(void)
{
	char	cb[5];

	init(cb);
	while (cb[0] <= '9')
	{
		while (cb[1] <= '9')
		{
			extension(cb);
		}
		cb[1] = '0';
		cb[0]++;
	}
}

void	init(char *cb)
{
	cb[0] = '0';
	cb[1] = '0';
	cb[2] = ' ';
	cb[3] = '0';
	cb[4] = '1';
}
