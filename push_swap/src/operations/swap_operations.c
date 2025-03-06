/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:48:42 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 21:19:54 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sa(t_stack *a)
{
	int	tmp_value;
	int	tmp_index;

	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	tmp_value = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = tmp_value;
	tmp_index = a->top->index;
	a->top->index = a->top->next->index;
	a->top->next->index = tmp_index;
}

void	sb(t_stack *b)
{
	int	tmp_value;
	int	tmp_index;

	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	tmp_value = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = tmp_value;
	tmp_index = b->top->index;
	b->top->index = b->top->next->index;
	b->top->next->index = tmp_index;
}
