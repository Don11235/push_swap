/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-cha <mben-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:36:01 by mben-cha          #+#    #+#             */
/*   Updated: 2025/02/27 14:37:45 by mben-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_start(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ')
		i++;
	return (i);
}

static int	find_end(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
		return (0);
	while (str[i])
		i++;
	i--;
	while (i > 0 && str[i] == ' ')
		i--;
	return (i);
}

static int	count_words(char *str)
{
	int	i;
	int	j;
	int	count;

	i = find_start(str);
	j = find_end(str);
	count = 0;
	if (i > j || str[0] == '\0')
		return (0);
	while (i <= j)
	{
		while (str[i] != ' ' && i <= j)
			i++;
		if (str[i] == ' ' && i <= j)
			count++;
		while (str[i] == ' ' && i <= j)
			i++;
	}
	return (count + 1);
}

static char	*extract_word(char *str, int *index)
{
	char	*pt;
	int		k;
	int		z;

	z = 0;
	k = *index;
	while (str[k] != ' ' && str[k])
		k++;
	pt = malloc(k - *index + 1);
	if (pt == NULL)
		return (NULL);
	while (*index < k)
		pt[z++] = str[(*index)++];
	pt[z] = '\0';
	while (str[*index] == ' ')
		(*index)++;
	return (pt);
}

char	**ft_split(char *str)
{
	int		i;
	int		len;
	int		z;
	int		*ind;
	char	**arr;

	i = find_start(str);
	len = count_words(str);
	arr = malloc((len + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	ind = &i;
	z = 0;
	while (z < len)
	{
		arr[z] = extract_word(str, ind);
		if (arr[z] == NULL)
		{
			free_allocated_memory(arr, z);
			return (NULL);
		}
		z++;
	}
	arr[z] = NULL;
	return (arr);
}
