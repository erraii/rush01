/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:06:58 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 17:31:05 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size.h"

int	factorial(int n)
{
	int	fact;
	int	i;

	fact = 1;
	i = 1;
	while (i <= n)
	{
		fact *= i;
		i++;
	}
	return (fact);
}

void	swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
