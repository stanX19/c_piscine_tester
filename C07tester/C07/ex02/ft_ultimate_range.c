/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:21:04 by myeow             #+#    #+#             */
/*   Updated: 2024/01/29 20:47:05 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	alloc_size;
	int	i;

	alloc_size = max - min;
	if (alloc_size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (alloc_size));
	if (*range == 0)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		(*range)[i] = min + i;
		++i;
	}
	return (alloc_size);
}
