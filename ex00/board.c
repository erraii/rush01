/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:34:46 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 17:51:58 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "size.h"

int	*seen_pairs(int *block, int *pairs);

void	ft_copy(int *r, int *L)
{
	int	j;

	j = 0;
	while (j < SIZE)
	{
		r[j] = L[j];
		j++;
	}
}

void	print_board(int r[][SIZE])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			c = r[i][j] + 48;
			write(1, &c, 1);
			if (j == (SIZE - 1))
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
}

int	search_same(int r[][SIZE])
{
	int	i;
	int	j;
	int	order;

	i = 0;
	while (i < (SIZE - 1))
	{
		j = i + 1;
		while (j < SIZE)
		{
			order = 0;
			while (order < SIZE)
			{
				if (r[i][order] == r[j][order])
					return (0);
				order++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	convert_board(int r[][SIZE])
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = i + 1;
		while (j < SIZE)
		{	
			if (!(i == j))
			{
				temp = r[i][j];
				r[i][j] = r[j][i];
				r[j][i] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_check(int r[][SIZE], int *clue, int *ps)
{
	int	i;

	if (search_same(r) == 0)
		return (0);
	i = 0;
	while (i < SIZE)
	{
		seen_pairs(r[i], ps);
		if ((ps[0] != clue[i + (SIZE * 2)]) || (ps[1] != clue[i + (SIZE * 3)]))
			return (0);
		i++;
	}
	convert_board(r);
	while ((SIZE - i) < SIZE)
	{
		seen_pairs(r[(SIZE - i)], ps);
		if ((ps[0] != clue[(SIZE - i)]) || (ps[1] != clue[((SIZE * 2) - i)]))
		{
			convert_board(r);
			return (0);
		}
		i--;
	}
	convert_board(r);
	return (1);
}
