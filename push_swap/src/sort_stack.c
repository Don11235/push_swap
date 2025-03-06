/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:44:41 by mben-cha          #+#    #+#             */
/*   Updated: 2025/03/06 12:38:55 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_sorted(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (a->top->next == NULL)
		return (1);
	first = a->top;
	second = a->top->next;
	while (first->next != NULL && second != NULL)
	{
		if (first->index > second->index)
			return (0);
		first = first->next;
		second = second->next;
	}
	return (1);
}

static int	size_stack(t_stack *stack)
{
	t_node	*n;
	int		count;

	count = 0;
	n = stack->top;
	while (n != NULL)
	{
		count++;
		n = n->next;
	}
	return (count);
}

static int	push_or_rotate_a(t_stack *a, t_stack *b, int i)
{
	int	j;
	int	a_size;
	int	b_size;

	j = 0;
	a_size = size_stack(a);
	b_size = size_stack(b);
	while (j < a_size && a->top != NULL)
	{
		if (check_sorted(a))
			break ;
		if ((a->top->index >> i) & 1)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
		else
		{
			pb(a, b);
			write(1, "pb\n", 3);
			b_size++; 
		}
		j++;
	}
	return (b_size);
}

static void	move_or_rotate_b(t_stack *a, t_stack *b, int i, int nb_bits)
{
	if (i + 1 < nb_bits)
	{
		if ((b->top->index >> (i + 1)) & 1)
		{
			pa(b, a);
			write(1, "pa\n", 3);
		}
		else
		{
			rb(b);
			write(1, "rb\n", 3);
		}
	}
}

void	sort_stack(t_stack *a, t_stack *b, int size)
{
	int	nb_bits;
	int	b_size;
	int	j;
	int	i;

	i = 0;
	nb_bits = max_bits(size);
	while (i < nb_bits)
	{
		j = 0;
		b_size = push_or_rotate_a(a, b, i);
		while (j < b_size && b->top != NULL)
		{
			move_or_rotate_b(a, b, i, nb_bits);
			j++;
		}
		i++;
	}
	while (b->top != NULL)
	{
		pa(b, a);
		write(1, "pa\n", 3);
	}
}
