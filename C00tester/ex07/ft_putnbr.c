/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:43:07 by stan              #+#    #+#             */
/*   Updated: 2022/04/08 12:46:00 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		placement;
	int		i;
	int		len;
	char	all[32];

	placement = 1;
	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	while (nb >= placement)
	{
		all[i] = (nb % (placement * 10)) / placement + 48;
		placement *= 10;
		i++;
	}
	len = i;
	while (i != -1)
	{
		i--;
		write(1, &all[i], 1);
	}
}
