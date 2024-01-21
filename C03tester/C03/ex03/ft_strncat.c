/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:18:28 by myeow             #+#    #+#             */
/*   Updated: 2024/01/21 13:07:36 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	append_i;

	i = 0;
	append_i = 0;
	while (dest[i])
		++i;
	while (src[append_i] && append_i < nb)
	{
		dest[i + append_i] = src[append_i];
		++append_i;
	}
	dest[i + append_i] = 0;
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
