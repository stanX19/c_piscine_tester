/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 00:04:03 by shatan            #+#    #+#             */
/*   Updated: 2024/01/30 18:02:07 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (2);
	i = nb;
	while (!ft_is_prime(i))
		i++;
	return (i);
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
