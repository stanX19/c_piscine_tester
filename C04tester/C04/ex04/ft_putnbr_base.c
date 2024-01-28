/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:41:30 by shatan            #+#    #+#             */
/*   Updated: 2024/01/28 13:24:13 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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
		if (hash[(int)((unsigned char)base[i])])
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		hash[(int)((unsigned char)base[i])] = 1;
		++i;
	}
	return (i);
}

void	recursion(long long int nbr, char *base_str, int base_nbr)
{
	if (nbr >= base_nbr)
		recursion(nbr / base_nbr, base_str, base_nbr);
	ft_putchar(base_str[nbr % base_nbr]);
}

void	ft_putnbr_base(int nbr, char *base_str)
{
	int				base_nbr;
	long long int	l_nbr;

	base_nbr = find_base(base_str);
	if (base_nbr < 2)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		l_nbr = nbr;
		l_nbr *= -1;
	}
	else
		l_nbr = nbr;
	recursion(l_nbr, base_str, base_nbr);
}
/*
int	main(void)
{
	char	*dec;
	char	*bin;
	char	*hex;
	char	*oct;

	dec = "0123456789";
	bin = "01";
	hex = "0123456789ABCDEF";
	oct = "poneyvif";
	return (0);
}
*/
