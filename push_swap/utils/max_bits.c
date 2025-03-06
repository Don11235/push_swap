/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_bits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:34:12 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 22:49:57 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_bits(int size)
{
	int	max_index;
	int	bit;

	bit = 0;
	if (size == 0 || size == 1)
		return (1);
	max_index = size - 1;
	while (max_index > 0)
	{
		bit++;
		max_index = max_index >> 1;
	}
	return (bit);
}
