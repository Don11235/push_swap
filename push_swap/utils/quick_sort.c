/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:59:58 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/21 11:58:29 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	partition(int *values, int low, int high)
{
	int	pivot;
	int	start;
	int	end;
	int	swp;

	pivot = values[low];
	start = low;
	end = high;
	while (start < end)
	{
		while (values[start] <= pivot && start < high)
			start++;
		while (values[end] > pivot && end > low)
			end--;
		if (start < end)
		{
			swp = values[start];
			values[start] = values[end];
			values[end] = swp;
		}
	}
	swp = values[low];
	values[low] = values[end];
	values[end] = swp;
	return (end); 
}

void	quick_sort(int *values, int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition(values, low, high);
		quick_sort(values, low, i - 1);
		quick_sort(values, i + 1, high);
	}
}
