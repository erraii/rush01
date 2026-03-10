/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:15:25 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 17:40:32 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "size.h"

void	ft_copy(int *r, int *L);
void	print_board(int r[][SIZE]);
int		ft_check(int r[][SIZE], int *clue, int *pairs);

void	calc_loop_size(unsigned int *loop_size, unsigned int comb_num)
{
	int	j;

	j = 1;
	*loop_size = comb_num;
	while (j < (SIZE))
	{
		*loop_size *= comb_num;
		j++;
	}
}

void	calculate_order(int comb_num, int *i)
{
	int	j;

	j = 1;
	i[SIZE - j] = 1;
	while (j < SIZE)
	{
		i[SIZE - 1 - j] = comb_num * i[SIZE - j];
		j++;
	}
}

int	solve(int **L, int *clue, int comb_num, unsigned int loop_size)
{
	unsigned int	n[3];
	int				i[SIZE];
	int				r[SIZE][SIZE];
	int				pairs[2];

	calculate_order(comb_num, i);
	n[0] = 0;
	while (n[0] < loop_size)
	{
		n[1] = 0;
		while (n[1] < SIZE)
		{
			n[2] = (n[0] / i[n[1]]) % comb_num;
			ft_copy(r[n[1]], L[n[2]]);
			n[1]++;
		}
		if (ft_check(r, clue, pairs) == 1)
		{
			print_board(r);
			return (0);
		}
		n[0]++;
	}
	write(1, "No solution found!\n", 19);
	return (0);
}
