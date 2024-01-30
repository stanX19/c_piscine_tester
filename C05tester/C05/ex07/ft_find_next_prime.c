/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:04:03 by shatan            #+#    #+#             */
/*   Updated: 2024/01/30 13:51:57 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ceil_sqrt(int x)
{
	int	start;
	int	end;
	int	mid;

	if (x < 0)
		return (0);
	if (x == 0 || x == 1)
		return (x);
	start = 1;
	end = x / 2 + 1;
	while (start < end)
	{
		mid = start + (end - start) / 2;
		if (mid * mid == x)
			return (mid);
		if (mid * mid < x)
			start = mid + 1;
		else
			end = mid;
	}
	return (end);
}

static int	ft_is_prime(int nb)
{
	int	i;
	int	sqrt_nb;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	sqrt_nb = ceil_sqrt(nb);
	while (i <= sqrt_nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (nb < 4)
		return (nb);
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = -3;
	while (++i < 100)
		//printf("%d, %d\n", i, ft_is_prime(i));
		printf("%d, %d\n", i, ft_find_next_prime(i));
	return (0);
}
*/
