/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:42:12 by myeow             #+#    #+#             */
/*   Updated: 2024/01/24 17:52:29 by shatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		++i;
	}
}
/*
int	main()
{
	char	*str = "qertuq";
	char	*str1 = "";

	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr(str1);
	ft_putchar('\n');
	return 0;
}
*/
