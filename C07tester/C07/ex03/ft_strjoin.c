/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:57:55 by shatan            #+#    #+#             */
/*   Updated: 2024/01/30 17:58:49 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (*str++)
		x++;
	return (x);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;
	int		total_len;

	total_len = 0;
	i = -1;
	while (++i < size)
		total_len += ft_strlen(strs[i]);
	total_len += (size - 1) * ft_strlen(sep) + 1;
	s = malloc(total_len);
	i = -1;
	c = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			s[c++] = sep[j++];
	}
	s[c] = '\0';
	return (s);
}
/*
int	main(void)
{
	char	*strs[] = {"this", "is", "some", "strings", "lol"};
	char	*sep;
	char	*result;

	sep = " yo ";
	result = ft_strjoin(5, strs, sep);
	if (!(result))
	{
		printf("%s\n", result);
		free(result);
	}
	else
		printf("Memory allocation failed\n");
}
*/