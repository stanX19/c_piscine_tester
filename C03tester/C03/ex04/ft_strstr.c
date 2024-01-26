/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:03:15 by shatan             #+#    #+#             */
/*   Updated: 2024/01/20 14:02:32 by shatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*find_substring(int needle, char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == *to_find)
		{
			j = 0;
			while (str[i + j] == to_find[j])
			{
				if (j == needle - 1)
					return (str + i);
				else if (j < needle)
					++j;
			}
		}
		++i;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		needle_ind;
	char	*result;

	result = 0;
	needle_ind = 0;
	while (to_find[needle_ind])
		++needle_ind;
	if (needle_ind == 0)
		return (str);
	else
	{
		result = find_substring(needle_ind, str, to_find);
		return (result);
	}
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char search[50] = "i\tHello";
	char str[50] = "\tHellod ert";
	//char str[100] = ""
	
	puts(strstr(str, search));
	puts(ft_strstr(str, search));
	return (0);
}
*/
