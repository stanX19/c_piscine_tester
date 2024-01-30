/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:24:22 by myeow             #+#    #+#             */
/*   Updated: 2024/01/30 18:37:23 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_space(char c);
int		get_val(int *hash_tab, char c);
void	set_val(int *hash_tab, char c, int val);
int		find_base(char *base, int *hash_tab);
int		ft_atoi_base(char *str, char *base);

int	check_base(char *base)
{
	int	hash_tab[256];
	int	b;

	b = -1;
	while (++b < 256)
		hash_tab[b] = -1;
	b = -1;
	while (base[++b])
	{
		if (get_val(hash_tab, base[b]) != -1)
			return (0);
		if (base[b] == '+' || base[b] == '-' || is_space(base[b]))
			return (0);
		set_val(hash_tab, base[b], b);
	}
	return (b);
}

int	get_nbr_length_base(int nbr, int base_length)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr)
	{
		nbr /= base_length;
		++len;
	}
	return (len);
}

void	ft_putnbr_base(int nbr, char *base, char *dest, int output_len)
{
	int				b;
	unsigned int	u_nbr;

	b = 0;
	u_nbr = (unsigned int) nbr;
	while (base[b])
		++b;
	if (nbr < 0)
	{
		dest[0] = '-';
		u_nbr = nbr * -1;
	}
	if (nbr == 0)
		dest[0] = *base;
	while (u_nbr)
	{
		dest[--output_len] = *(base + u_nbr % b);
		u_nbr /= b;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		value_in_dec;
	int		b;
	int		output_len;
	char	*str;

	if (check_base(base_from) < 2 || check_base(base_to) < 2)
		return (0);
	value_in_dec = ft_atoi_base(nbr, base_from);
	b = check_base(base_to);
	output_len = get_nbr_length_base(value_in_dec, b);
	str = (char *)malloc(sizeof(char) * (output_len + 1));
	if (!(str))
		return (0);
	str[output_len] = 0;
	ft_putnbr_base(value_in_dec, base_to, str, output_len);
	return (str);
}
