/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seen.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:34:02 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 15:40:52 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size.h"

int	find_seen_begin(int *block)
{
	int	bn;
	int	cmp;
	int	seen;

	bn = 1;
	seen = SIZE;
	while (bn < SIZE)
	{
		cmp = 0;
		while (cmp < bn)
		{
			if (block[bn] < block[cmp])
			{
				seen--;
				break ;
			}
			cmp++;
		}
		bn++;
	}
	return (seen);
}

int	find_seen_end(int *block)
{
	int	bn;
	int	cmp;
	int	seen;

	bn = SIZE - 2;
	seen = SIZE;
	while (bn >= 0)
	{
		cmp = SIZE - 1;
		while (cmp > bn)
		{
			if (block[bn] < block[cmp])
			{
				seen--;
				break ;
			}
			cmp--;
		}
		bn--;
	}
	return (seen);
}

int	*seen_pairs(int *block, int *pairs)
{
	pairs[0] = find_seen_begin(block);
	pairs[1] = find_seen_end(block);
	return (pairs);
}
