/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_duplist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:18:37 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/15 22:13:20 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*get_lis => git LIS array */
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
	while (j >= 0)
	{
		lis_tab[len] = tab[j];
		j = index_tab[j];
		len--;
	}
	return (lis_tab);
}

/*get_duplist => get a duplicate stack tmp that
 have the min value, in the origin stack, in the top */
t_stack	*get_duplist(t_stack *stack_a, int size)
{
	t_stack	*stack_tmp;

	stack_tmp = copy_list(stack_a);
	stack_tmp = get_newlist(stack_tmp, size);
	//  print_stack(stack_tmp);
	return (stack_tmp);
}
