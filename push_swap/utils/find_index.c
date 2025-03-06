/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:49:24 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 22:49:43 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	*create_sorted_copy(int *values, int size)
{
	int	*copy;
	int	i;

	i = 0;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return (0);
	while (i < size)
	{
		copy[i] = values[i];
		i++;
	}
	quick_sort(copy, 0, size - 1);
	return (copy);
}

int	find_index_sorted(int *values, int val, int size)
{
	int	left;
	int	right;
	int	mid;
	int	*cpy;

	left = 0;
	right = size - 1;
	cpy = create_sorted_copy(values, size);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (cpy[mid] == val)
			return (free(cpy), mid);
		else if (val < cpy[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	free(cpy);
	return (-1);
}
