/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:06:06 by mben-cha          #+#    #+#             */
/*   Updated: 2025/03/01 22:11:15 by mben-cha         ###   ########.fr       */
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

static void	sort_three(t_stack *a)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (a->top->index > a->top->next->index)
		{
			sa(a);
			write(1, "sa\n", 3);
		}
		if (check_sorted(a) == 0)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
		else
			break ;
		i++;
	}
}

static void	push_to_b(t_stack *a, t_stack *b)
{
	while (b->top != NULL)
	{
		pa(b, a);
		write(1, "pa\n", 3);
	}
}

static void	sort_five_or_four(t_stack *a, t_stack *b, int size)
{
	int	i;

	i = 0;
	if (check_sorted(a) == 1)
		return ;
	while (i++ < size)
	{
		if (a->top->index < size / 2)
		{
			pb(a, b);
			write(1, "pb\n", 3);
		}
		else
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
	sort_three(a);
	if (b->top->index < b->top->next->index)
	{
		sb(b);
		write(1, "sb\n", 3);
	}
	push_to_b(a, b);
}

void	small_sort(t_stack *a, t_stack *b, int size)
{
	if (size == 3)
		sort_three(a);
	else if (size == 4 || size == 5)
		sort_five_or_four(a, b, size);
}
