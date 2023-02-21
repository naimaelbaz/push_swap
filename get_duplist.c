/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_duplist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:18:37 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/21 04:24:59 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_lis(int *tab, int size)
{
	int	*lis_tab;
	int	len;
	int	j;
	int	*index_tab;
	int	*len_tab;

	index_tab = get_index_tab(tab, size);
	len_tab = get_length(tab, size);
	len = max_len(len_tab, size) - 1;
	j = get_index(len_tab, size);
	lis_tab = malloc(sizeof(int) * len);
	if (!lis_tab)
		return (NULL);
	while (j >= 0)
	{
		lis_tab[len] = tab[j];
		j = index_tab[j];
		len--;
	}
	return (free(index_tab), free(len_tab), lis_tab);
}

t_stack	*get_newlist(t_stack *stack_tmp, int size)
{
	int			pos;
	int			min;

	pos = get_position(stack_tmp);
	min = have_min_number(stack_tmp);
	while (stack_tmp->data != min)
	{
		if (pos <= (size / 2))
			rotate_a_tmp(&stack_tmp);
		else if (pos > (size / 2))
			rev_rotate_a_tmp(&stack_tmp);
	}
	return (stack_tmp);
}

t_stack	*get_duplist(t_stack *stack_a, int size)
{
	t_stack	*stack_tmp;

	stack_tmp = copy_list(stack_a);
	stack_tmp = get_newlist(stack_tmp, size);
	return (stack_tmp);
}
