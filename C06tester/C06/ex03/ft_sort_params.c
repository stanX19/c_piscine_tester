/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:08:31 by stan              #+#    #+#             */
/*   Updated: 2022/04/14 19:18:10 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned int	s1i;
	unsigned int	s2i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	s1i = s1[i];
	s2i = s2[i];
	return (s1i - s2i);
}

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(char **array, int len)
{
	int	sorted;
	int	i;

	sorted = 0;
	i = 1;
	while (sorted != len - 2)
	{
		sorted = 0;
		while (i < len - 1)
		{
			if (ft_strcmp(array[i], array[i + 1]) > 0)
				swap(&array[i], &array[i + 1]);
			else
				sorted++;
			i++;
		}
		len--;
		i = 1;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	bubble_sort(argv, argc);
	i = 0;
	while (i++ < argc - 1)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
	}
	return (0);
}
