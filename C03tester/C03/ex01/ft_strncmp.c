/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:39:26 by shatan             #+#    #+#             */
/*   Updated: 2024/01/24 15:31:20 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		++i;
	c1 = s1[i];
	c2 = s2[i];
	if (i < n)
		return ((int)c1 - c2);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "afdsafds";
	char	str2[] = "afdsafdsjfsdf";
	int		n;
	int		result;
	int		real_result;

	n = 10;
	//n cant be less than 0 right? since it is an unsigned int
	result = ft_strncmp(str1, str2, n);
	real_result = strncmp(str1, str2, n);
	printf("%d\n%d", result, real_result);
	return (0);
}
*/
