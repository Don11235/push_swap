/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocated_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:38:22 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 22:41:35 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_allocated_memory(char **p, int i)
{
	while (i > 0)
	{
		free(p[i - 1]);
		i--;
	}
	free(p);
}
