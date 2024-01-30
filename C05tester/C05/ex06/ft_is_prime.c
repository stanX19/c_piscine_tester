/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:10:41 by shatan            #+#    #+#             */
/*   Updated: 2024/01/30 13:51:50 by shatan           ###   ########.fr       */
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

int	ft_is_prime(int nb)
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
/*
#include <stdio.h>

int	main(void)
{
	int	i;

	i = -5;
	while (i++ < 1000)
	{
		if (ft_is_prime(i))
			printf("%d, ", i);
	}
	return (0);
}
*/
