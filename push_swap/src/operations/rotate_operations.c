/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:42:31 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 21:18:22 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*top_a;

	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	top_a = a->top;
	a->top = a->top->next;
	top_a->prev->next = top_a;
	top_a->next = NULL;
}

void	rb(t_stack *b)
{
	t_node	*top_b;

	if (b == NULL || b->top == NULL || b->top->next == NULL)
		return ;
	top_b = b->top;
	b->top = b->top->next;
	top_b->prev->next = top_b;
	top_b->next = NULL;
}
