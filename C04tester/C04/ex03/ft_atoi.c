/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:41:17 by shatan            #+#    #+#             */
/*   Updated: 2024/01/26 18:41:18 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int				sign;
	int				i;
	unsigned int	result;

	sign = 1;
	i = 0;
	result = 0;
	while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) && str[i])
		++i;
	while ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		++i;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return (((int) result) * sign);
}
/*
#include <stdio.h>
int	main()
{
	char *str = "\n\t\r\v\f ---+--1000";

	printf("%d\n", ft_atoi(str));
	return (0);
}
*/
