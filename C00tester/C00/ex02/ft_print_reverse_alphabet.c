/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stan <stan@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:42:18 by stan              #+#    #+#             */
/*   Updated: 2022/04/07 20:03:25 by stan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	ztoa[27];
	char	*atoz;
	int		len;
	int		i;

	i = 0;
	atoz = "abcdefghijklmnopqrstuvwxyz";
	len = 26;
	while (i < len)
	{
		ztoa[len - 1 - i] = atoz[i];
		i++;
	}
	write(1, &ztoa, 26);
}
