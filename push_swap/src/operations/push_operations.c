/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:28:18 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 21:19:34 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_stack *b, t_stack *a)
{
	t_node	*top_b;

	if (b == NULL || b->top == NULL)
		return ;
	top_b = b->top;
	b->top = top_b->next;
	if (b->top != NULL)
		b->top->prev = top_b->prev;
	top_b->next = a->top;
	if (a->top == NULL)
		top_b->prev = top_b;
	if (a->top != NULL)
	{
		top_b->prev = a->top->prev;
		a->top->prev = top_b;
	}
	a->top = top_b;
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*top_a;

	if (a == NULL || a->top == NULL)
		return ;
	top_a = a->top;
	a->top = top_a->next;
	if (a->top != NULL)
		a->top->prev = top_a->prev;
	top_a->next = b->top;
	if (b->top == NULL)
		top_a->prev = top_a;
	if (b->top != NULL)
	{
		top_a->prev = b->top->prev;
		b->top->prev = top_a;
	}
	b->top = top_a;
}
