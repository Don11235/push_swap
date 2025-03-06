/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:55:48 by mben-cha          #+#    #+#             */
/*   Updated: 2025/03/01 16:16:39 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	is_integer(char *argv[])
{
	int		i;
	int		j;
	char	**pt;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		j = 0;
		pt = ft_split(argv[i]);
		if (pt == NULL)
			return (-1);
		if (pt[j] == NULL)
			return (free(pt), 0);
		while (pt[j])
		{
			if (is_valid_number(pt[j]) == 0)
				return (free_split(pt), 0);
			j++;
		}
		free_split(pt);
		i++;
	}
	return (1);
}

static int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_range(char *argv[])
{
	int		i;
	int		j;
	char	**pt;

	i = 1;
	while (argv[i])
	{
		j = 0;
		pt = ft_split(argv[i]);
		if (pt == NULL)
			return (-1);
		while (pt[j])
		{
			if (is_valid_int_length(pt[j]) == 0)
				return (free_split(pt), 0);
			j++;
		}
		free_split(pt);
		i++;
	}
	return (1);
}

static int	*allocate_and_check(char *argv[])
{
	int	*num;

	num = malloc(sizeof(int) * count_numbers(argv));
	if (num == NULL)
		return (NULL);
	return (num);
}

int	*parse_input(char *argv[])
{
	int		*num;
	int		i;
	int		j;
	char	**pt;
	int		k;

	i = 0;
	k = 0;
	if (is_integer(argv) == 0 || check_range(argv) == 0)
		return (NULL);
	num = allocate_and_check(argv);
	while (argv[++i])
	{
		pt = ft_split(argv[i]);
		if (pt == NULL)
			return (free(num), NULL);
		j = -1;
		while (pt[++j])
			num[k++] = (int)ft_atol(pt[j]);
		free_split(pt);
	}
	if (check_duplicates(num, count_numbers(argv)) == 0)
		return (free(num), NULL);
	return (num);
}
