/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myeow <myeow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:03:49 by myeow             #+#    #+#             */
/*   Updated: 2024/01/29 20:47:42 by myeow            ###   ########.fr       */
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

char	*ft_mallocstr(int size, char **strs, char *sep)
{
	int		malloc_len;
	int		i;
	char	*alloc_str;

	malloc_len = 0;
	i = -1;
	while (++i < size)
		malloc_len += ft_strlen(strs[i]);
	malloc_len += (size - 1) * ft_strlen(sep);
	if (size <= 0)
		malloc_len = 1;
	alloc_str = (char *)malloc(sizeof(char) * malloc_len);
	if (!alloc_str)
		return (0);
	return (alloc_str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	char	*catstr;
	int		catstr_l;

	catstr = ft_mallocstr(size, strs, sep);
	catstr_l = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j])
			catstr[catstr_l++] = strs[i][j];
		j = -1;
		while (i < size - 1 && sep[++j])
			catstr[catstr_l++] = sep[j];
	}
	*(catstr + catstr_l) = 0;
	return (catstr);
}
