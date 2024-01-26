/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:41 by shatan             #+#    #+#             */
/*   Updated: 2024/01/20 01:00:53 by shatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb < 4)
		return (1);
	else
	{
		while (i < ((nb + 1) / 2) + 1)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
	}
	return (1);
}
/*
#include <stdio.h>
int	main()
{
	int i = -5;
	while (i++ < 1000)
	{
		if (ft_is_prime(i))
			printf("%d, ", i);
	}
	return (0);
}
*/
