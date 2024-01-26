/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:04:03 by shatan             #+#    #+#             */
/*   Updated: 2024/01/20 01:02:18 by shatan            ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (nb < 3)
		return (2);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
/*
#include <stdio.h>
int	main()
{
	int	i = -3;

	while (++i < 100)
		//printf("%d, %d\n", i, ft_is_prime(i));
		printf("%d, %d\n", i, ft_find_next_prime(i));
	return (0);
}
*/
