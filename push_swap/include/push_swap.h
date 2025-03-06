/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:16:59 by mben-cha          #+#    #+#             */
/*   Updated: 2025/03/01 14:16:14 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;		
}					t_node;

typedef struct s_stack{
	t_node	*top;
}			t_stack;

void	quick_sort(int *values, int low, int high);
void	sort_stack(t_stack *a, t_stack *b, int size);
int		max_bits(int size);
int		find_index_sorted(int *values, int val, int size);
char	**ft_split(char *str);
void	free_split(char **array);
int		is_valid_number(char *str);
int		is_valid_int_length(char *str);
void	free_stack(t_stack *stack);
int		*parse_input(char *argv[]);
int		count_numbers(char *argv[]);
long	ft_atol(const char *str);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	small_sort(t_stack *a, t_stack *b, int size);
void	free_allocated_memory(char **p, int i);
t_stack	*create_stack(void);
t_stack	*initialize_stack(int *values, int size);
#endif