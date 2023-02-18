/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:11:05 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/17 23:40:42 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_tab(int *index_tab, int *len_tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
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
	while (i < size)
		len_tab[i++] = 1;
	i = 1;
	j = 0;
	while (i < size)
	{
		while (j != i)
		{
			if (tab[j] < tab[i] && len_tab[j] + 1 > len_tab[i])
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
	int	i;
	int	j;
	int	*index_tab;
	int	*len_tab;

	i = 0;
	len_tab = malloc(size * sizeof(int));
	index_tab = malloc(size * sizeof(int));
	insert_tab(index_tab, len_tab, size);
	i = 1;
	j = 0;
	while (i < size)
	{
		j = 0;
		while (j != i)
		{
			if (tab[j] < tab[i] && len_tab[j] + 1 > len_tab[i])
			{
				index_tab[i] = j;
				len_tab[i] = len_tab[j] + 1;
			}
			j++;
		}
		i++;
	}
	return (free(len_tab), index_tab);
}

int	get_index(int *len_tab, int size)
{
	int	i;
	int	j;
	int	max_index;

	i = 0;
	j = 0;
	max_index = 0;
	while (i < size)
	{
		if (len_tab[i] > len_tab[max_index])
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
