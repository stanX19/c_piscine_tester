/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:50:27 by stan              #+#    #+#             */
/*   Updated: 2022/04/12 14:52:14 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	sorted;
	int	i;

	sorted = 0;
	while (sorted != size - 1)
	{
		i = 0;
		sorted = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
				swap(&tab[i], &tab[i + 1]);
			else
				sorted++;
			i++;
		}
	}
}
