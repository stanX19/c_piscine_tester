/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:44:24 by shatan             #+#    #+#             */
/*   Updated: 2024/01/24 15:27:01 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	d_idx;
	int	s_idx;

	d_idx = 0;
	s_idx = 0;
	while (dest[d_idx])
		d_idx++;
	while (src[s_idx])
	{
		dest[d_idx + s_idx] = src[s_idx];
		s_idx++;
	}
	dest[d_idx + s_idx] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char str1[1000] = "asf\neter";
	char str1_cpy[100] = "asf\neter";
	char str2[] = "r\teyut";

	ft_strcat(str1, str2);
	puts(str1);

	strcat(str1_cpy, str2);
	puts(str1_cpy);
	return 0;
}
*/
