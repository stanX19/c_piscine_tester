/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:08:57 by shatan             #+#    #+#             */
/*   Updated: 2024/01/25 14:43:29 by shatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_recurse(int nb, int i)
{
	if (nb < 1)
		return (0);
	if (nb > 2147395600)
		return (0);
	if (nb == i * i)
		return (i);
	if (nb > i * i)
		return (ft_sqrt_recurse(nb, i + 1));
	return (0);
}

int	ft_sqrt(int nb)
{
	return (ft_sqrt_recurse(nb, 1));
}
/*
#include <stdio.h>
int main()
{
	int i = -5;
	while (i <= 10)
	{
		printf("%d, %d\n", ft_sqrt(i), i);
		++i;
	}
	return (0);
}
*/
