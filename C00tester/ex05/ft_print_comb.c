/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 12:41:44 by stan              #+#    #+#             */
/*   Updated: 2022/04/10 15:02:46 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	i;
	char	t;
	char	h;

	i = 50;
	t = 49;
	h = 48;
	while (h < 58)
	{
		while (t < 58)
		{
			while (i < 58)
			{
				write(1, &h, 1);
				write(1, &t, 1);
				write(1, &i, 1);
				if (h != 55)
					write(1, ", ", 2);
				i++;
			}
			i = t++ + 2;
		}
		t = h++ + 1;
	}
}
