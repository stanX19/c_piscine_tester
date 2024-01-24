/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:36:39 by myeow             #+#    #+#             */
/*   Updated: 2024/01/20 21:41:10 by myeow            ###   ########.fr       */
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
