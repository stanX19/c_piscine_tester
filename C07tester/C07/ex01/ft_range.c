/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:55:40 by myeow             #+#    #+#             */
/*   Updated: 2024/01/31 16:04:03 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	alloc_size;
	int				*array;
	int				i;

	if (max <= min)
		return (0);
	alloc_size = max - min;
	array = (int *)malloc(sizeof(int) * (max - min));
	if (!array)
		return (0);
	i = 0;
	while (min + i < max)
	{
		array[i] = min + i;
		++i;
	}
	return (array);
}
