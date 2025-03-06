/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:16:35 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/23 21:19:14 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	rra(t_stack *a)
{
	if (a == NULL || a->top == NULL || a->top->next == NULL)
		return ;
	a->top->prev->prev->next = NULL;
	a->top->prev->next = a->top;
	a->top = a->top->prev;
}
