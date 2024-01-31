/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:21 by shatan            #+#    #+#             */
/*   Updated: 2024/01/27 23:28:32 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *str, int size)
{
	char	*c;
	int		i;

	i = -1;
	c = malloc((size + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	while (*str)
		c[++i] = *str++;
	c[++i] = '\0';
	return (c);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*c;
	int			i;

	i = -1;
	c = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (c == NULL)
		return (NULL);
	while (++i < ac)
	{
		c[i].size = ft_strlen(av[i]);
		c[i].str = av[i];
		c[i].copy = ft_strdup(av[i], c[i].size);
	}
	c[i].str = 0;
	return (c);
}

// #include <stdio.h>

// int	main(int argc, char **argv)
// {
// 	t_stock_str	*tab;
// 	int			i;

// 	i = 0;
// 	tab = ft_strs_to_tab(argc, argv);
// 	while (++i < argc)
// 	{
// 		printf("Size: %d\n", tab[i].size);
// 		printf("Str: %s\n", tab[i].str);
// 		printf("Copy: %s\n", tab[i].copy);
// 	}
// 	free(tab);
// 	return (0);
// }
