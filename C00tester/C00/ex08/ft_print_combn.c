/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:10:06 by shatan            #+#    #+#             */
/*   Updated: 2024/01/17 14:17:45 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	recur(char *buf, char start, int idx, int n)
{
	buf[idx] = start;
	while (buf[idx] <= '9')
	{
		if (idx == n - 1)
		{
			write(1, buf, n);
			if (buf[0] != '9' - n + 1)
				write(1, ", ", 2);
		}
		else
			recur(buf, buf[idx] + 1, idx + 1, n);
		buf[idx]++;
	}
}

void	ft_print_combn(int n)
{
	char	buf[10];

	recur(buf, '0', 0, n);
}
