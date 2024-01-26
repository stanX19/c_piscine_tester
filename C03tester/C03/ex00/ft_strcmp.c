/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:49:02 by shatan             #+#    #+#             */
/*   Updated: 2024/01/24 15:31:12 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	c1 = *s1;
	c2 = *s2;
	return ((int)c1 - c2);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "MBGiwr";
	char	str2[] = "MBG";
	int		result;
	int		real_result;

	result = ft_strcmp(str1, str2);
	real_result = strcmp(str1, str2);
	printf("%d\n%d", result, real_result);
	return (0);
}
*/
