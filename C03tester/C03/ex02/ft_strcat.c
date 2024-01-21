/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:44:24 by myeow             #+#    #+#             */
/*   Updated: 2024/01/20 14:06:20 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	while (*(dest + d))
		d++;
	while (*(src + s))
	{
		*(dest + d + s) = *(src + s);
		s++;
	}
	*(dest + d + s) = 0;
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
