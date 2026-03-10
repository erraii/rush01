/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:05:10 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 17:34:13 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "size.h"

void	swap(int *a, int *b);
int		factorial(int n);

void	write_perm_to_memory(int **mem_add, int	*count, int *st_arr)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		mem_add[*count][i] = st_arr[i];
		i++;
	}
	(*count)++;
}

int	**allocate_mem(int all_possible)
{
	int	**arr;
	int	i;

	arr = malloc(all_possible * sizeof(int *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < all_possible)
	{
		arr[i] = malloc(SIZE * sizeof(int));
		if (!arr[i])
			return (NULL);
		i++;
	}
	return (arr);
}

void	gen_perm_rec(int **mem, int *count, int *arr, int start)
{
	int	i;

	if (start == SIZE)
	{
		write_perm_to_memory(mem, count, arr);
		return ;
	}
	i = start;
	while (i < SIZE)
	{
		swap(&arr[start], &arr[i]);
		gen_perm_rec(mem, count, arr, start + 1);
		swap(&arr[start], &arr[i]);
		i++;
	}
}

void	generate_combinations(int ***comb_addr, int *all_possible)
{
	int	start[SIZE];
	int	i;
	int	count;

	*all_possible = factorial(SIZE);
	*comb_addr = allocate_mem(*all_possible);
	if (!(*comb_addr))
		return ;
	i = 0;
	while (i < SIZE)
	{
		start[i] = i + 1;
		i++;
	}
	count = 0;
	gen_perm_rec(*comb_addr, &count, start, 0);
}
