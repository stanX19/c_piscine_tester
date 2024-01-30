/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:03:52 by myeow             #+#    #+#             */
/*   Updated: 2024/01/29 20:46:00 by myeow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*origin;

	origin = dest;
	while (*src != 0)
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = 0;
	return (origin);
}

char	*ft_strdup(char *src)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (str == 0)
		return (0);
	str = ft_strcpy(str, src);
	return (str);
}
