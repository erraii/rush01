/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecakiray <ecakiray@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:56:40 by ecakiray          #+#    #+#             */
/*   Updated: 2026/03/10 15:43:46 by ecakiray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "size.h"

int	atoi_(char argc)
{
	if (argc >= 49 && argc <= (48 + SIZE))
		return (argc - 48);
	else
		return (0);
}

int	ft_atoi(int *arr, char *str)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			ret = atoi_(str[i]);
			if (ret == 0)
				return (0);
			else
				arr[j] = ret;
			j++;
			if (j > (4 * SIZE))
				return (0);
		}
		i++;
	}
	if (j != (4 * SIZE))
		return (0);
	return (1);
}
