/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:40:42 by shatan            #+#    #+#             */
/*   Updated: 2024/01/30 13:13:49 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = "wertoy";
	char	*str1 = "";

	printf("%d, %d\n", ft_strlen(str), ft_strlen(str1));
}
*/
