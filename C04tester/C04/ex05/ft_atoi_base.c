/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:53:20 by myeow             #+#    #+#             */
/*   Updated: 2024/01/24 18:22:08 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_base(char *base)
{
	int		i;
	char	hash[256];

	i = 0;
	while (i < 256)
		hash[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (hash[(int)base[i]])
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		hash[(int)base[i]] = 1;
		++i;
	}
	return (i);
}

int	str_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int				base_len;
	int				sign;
	int				idx;
	long long int	ret;

	base_len = find_base(base);
	if (base_len < 2)
		return (0);
	sign = 1;
	ret = 0;
	while ((str[idx] == ' ' || (str[idx] >= 9 && str[idx] <= 13)) && str[idx])
		++idx;
	while ((str[idx] == '-' || str[idx] == '+') && str[idx])
	{
		if (str[idx++] == '-')
			sign *= -1;
	}
	while (str[idx])
	{
		ret = ret * base_len + str_find(base, str[idx]);
	}
	return ((int)(ret * sign));
}
