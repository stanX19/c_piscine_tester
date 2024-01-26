/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shatan <shatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:03:09 by shatan             #+#    #+#             */
/*   Updated: 2024/01/25 00:07:41 by shatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putdigit(int i)
{
	i += 48;
	write(1, &i, 1);
}

int	checksafe(int *board, int row, int col)
{
	int	i;

	i = -1;
	while (++i < row)
	{
		if (board[i] == col)
			return (0);
		if (i + board[i] == row + col)
			return (0);
		if (i - board[i] == row - col)
			return (0);
	}
	return (1);
}

void	find_solution(int *board, int *sol, int row)
{
	int	col;
	int	i;

	if (row == 10)
	{
		*sol += 1;
		i = -1;
		while (++i < 10)
			ft_putdigit(board[i]);
		write(1, "\n", 1);
	}
	else
	{
		col = -1;
		while (++col < 10)
		{
			if (checksafe(board, row, col))
			{
				board[row] = col;
				find_solution(board, sol, row + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	sol;

	i = -1;
	while (++i < 10)
		board[i] = -1;
	sol = 0;
	find_solution(board, &sol, 0);
	return (sol);
}
/*
#include <stdio.h>
int	main()
{
	int i = ft_ten_queens_puzzle();
	printf("%d\n", i);
	return (0);
}
*/
