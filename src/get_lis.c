/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:11:05 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/01 17:59:12 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_tab(int *index_tab, int *len_tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		index_tab[i] = -1;
		len_tab[i] = 1;
		i++;
	}
}

int	*get_length(int *tab, int size)
{
	int	i;
	int	j;
	int	*len_tab;

	i = 0;
	len_tab = malloc(size * sizeof(int));
	if (!len_tab)
		return (NULL);
	while (i < size)
		len_tab[i++] = 1;
	i = 1;
	j = 0;
	while (i < size)
	{
		while (j != i)
		{
			if (tab[j] < tab[i] && len_tab[j] + 1 >= len_tab[i])
				len_tab[i] = len_tab[j] + 1;
			j++;
		}
		i++;
		j = 0;
	}
	return (len_tab);
}

int	*get_index_tab(int *tab, int size)
{
	int	*index_tab;
	int	*len_tab;

	len_tab = malloc(size * sizeof(int));
	if (!len_tab)
		return (NULL);
	index_tab = malloc(size * sizeof(int));
	if (!index_tab)
		return (NULL);
	insert_tab(index_tab, len_tab, size);
	index_tab = get_tab(tab, len_tab, index_tab, size);
	return (free(len_tab), index_tab);
}

int	get_index(int *len_tab, int size)
{
	int	i;
	int	max_index;

	i = 1;
	max_index = 0;
	while (i < size)
	{
		if (len_tab[i] >= len_tab[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	max_len(int *len_tab, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (i < size)
	{
		if (len_tab[i] > len)
			len = len_tab[i];
		i++;
	}
	return (len);
}
