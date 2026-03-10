/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:34:02 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 17:42:18 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "size.h"

int		ft_atoi(int *arr, char *str);
void	generate_combinations(int ***comb_addr, int *all_possible);
int		solve(int **L, int *clue, int comb_num, int loop_size);
void	calc_loop_size(unsigned int *loop_size, int comb_num);

void	free_memory(int **comb_addr, int all_possible)
{
	int		i;
	int		*currentptr;

	i = 0;
	while (i < all_possible)
	{
		currentptr = comb_addr[i];
		free(currentptr);
		i++;
	}
}

int	main(int argn, char **argv)
{
	int				clue[SIZE * 4];
	int				**combinations;
	int				comb_num;
	unsigned int	loop_size;

	combinations = NULL;
	if ((argn != 2) || (ft_atoi(clue, argv[1]) == 0))
	{
		write(1, "Data format error!\n", 19);
		return (1);
	}
	generate_combinations(&combinations, &comb_num);
	if (combinations == NULL)
	{
		write(1, "ERROR: Memory overflow\n", 23);
		return (1);
	}
	calc_loop_size(&loop_size, comb_num);
	solve(combinations, clue, comb_num, loop_size);
	free_memory(combinations, comb_num);
	return (0);
}
