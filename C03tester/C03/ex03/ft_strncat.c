/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:18:28 by myeow             #+#    #+#             */
/*   Updated: 2024/01/24 15:27:27 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				dst_len;
	unsigned int	src_idx;

	dst_len = 0;
	src_idx = 0;
	while (dest[dst_len])
		++dst_len;
	while (src[src_idx] && src_idx < nb)
	{
		dest[dst_len + src_idx] = src[src_idx];
		++src_idx;
	}
	dest[dst_len + src_idx] = 0;
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char	str1[8] = "worywoe";
	char	str2[50] = "weuouriow";
	char	stra[50] = "worywoe";
	char	strb[50] = "weuouriow";

	strncat(str1, str2, 15);
	puts(str1);
	strncat(stra, strb, 15);
	puts(stra);
	return (0);
}
*/
