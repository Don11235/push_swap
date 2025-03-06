/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:28:46 by mben-cha          #+#    #+#             */
/*   Updated: 2025/03/01 22:35:15 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*parse;
	int		size;

	if (argc == 1)
		return (0);
	parse = parse_input(argv);
	if (parse == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	size = count_numbers(argv);
	stack_a = initialize_stack(parse, size);
	stack_b = create_stack();
	if (size >= 3 && size <= 5)
		small_sort(stack_a, stack_b, size);
	else
		sort_stack(stack_a, stack_b, size);
	free_stack(stack_a);
	free_stack(stack_b);
}
