/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:07:21 by myeow             #+#    #+#             */
/*   Updated: 2024/01/22 15:38:16 by shatan           ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (*(src + i) && (dest_len + i) < (size - 1))
	{
		*(dest + dest_len + i) = *(src + i);
		++i;
	}
	*(dest + dest_len + i) = 0;
	return (dest_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char	dest[100] = "=";
	char	src[100] = "f";
	char	dest1[100] = "=";
	char	src1[100] = "f";

	unsigned int	size = 100;

	printf("%u, %u\n", strlcat(dest, src, size), ft_strlcat(dest1, src1, size));
	puts(dest);
	puts(dest1);
	return 0;
}
*/
