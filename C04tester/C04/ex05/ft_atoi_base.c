/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:53:20 by shatan            #+#    #+#             */
/*   Updated: 2024/01/26 18:40:01 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static inline int	get_index(int hash[256], char c)
{
	unsigned char	c2;

	c2 = c;
	return (hash[(int)c2]);
}

static inline void	set_index(int hash[256], char c, int val)
{
	unsigned char	c2;

	c2 = c;
	hash[(int)c2] = val;
}

static int	init_base(char *base, int hash[256])
{
	int	i;

	i = 0;
	while (i < 256)
		hash[i++] = -1;
	i = 0;
	while (base[i])
	{
		if (get_index(hash, base[i]) != -1)
			return (0);
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		set_index(hash, base[i], i);
		++i;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int				base_len;
	int				sign;
	int				idx;
	long long int	ret;
	int				hash[256];

	base_len = init_base(base, hash);
	if (base_len < 2)
		return (0);
	sign = 1;
	ret = 0;
	idx = 0;
	while (str[idx] && str[idx] == ' ')
		++idx;
	while ((str[idx] == '-' || str[idx] == '+') && str[idx])
	{
		if (str[idx++] == '-')
			sign *= -1;
	}
	while (get_index(hash, str[idx]) != -1)
	{
		ret = ret * base_len + get_index(hash, str[idx]);
		++idx;
	}
	return ((int)(ret * sign));
}
