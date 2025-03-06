/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:58:00 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 21:31:05 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	handle_allocation_failure(t_stack *stack, t_node *new)
{
	if (new == NULL) 
	{
		free_stack(stack);
		return ;
	}
}

static void	push(t_stack *stack, int *values, int size)
{
	int		i;
	t_node	*new;

	i = 0;
	while (i < size)
	{
		new = malloc(sizeof(t_node));
		handle_allocation_failure(stack, new);
		new->value = values[i];
		new->index = find_index_sorted(values, values[i], size);
		new->next = NULL;
		if (stack->top == NULL) 
		{
			new->prev = new;
			stack->top = new;
		}
		else
		{
			new->prev = stack->top->prev;
			stack->top->prev->next = new;
			stack->top->prev = new;
		}
		i++;
	}
	free(values);
}

t_stack	*initialize_stack(int *values, int size)
{
	t_stack	*stack;

	stack = create_stack();
	push(stack, values, size);
	return (stack);
}
