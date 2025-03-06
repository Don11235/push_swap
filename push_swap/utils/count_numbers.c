/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:28:05 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/09 23:02:48 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_numbers(char *argv[])
{
	char	**pt;
	int		i;
	int		j;
	int		size;

	i = 1;
	size = 0;
	while (argv[i])
	{
		j = 0;
		pt = ft_split(argv[i]);
		if (pt == NULL)
			return (-1);
		while (pt[j++])
			size++;
		free_split(pt);
		i++;
	}
	return (size);
}
