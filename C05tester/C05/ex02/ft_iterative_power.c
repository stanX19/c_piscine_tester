/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:02:24 by shatan            #+#    #+#             */
/*   Updated: 2024/01/30 13:51:39 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (nb >= -1 && nb <= 1)
		return (nb * ((power % 2) * 1 + !(power % 2) * nb));
	else
	{
		while (power-- > 0)
			result *= nb;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d", ft_iterative_power(5, 0));
	return (0);
}
*/
