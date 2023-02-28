/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_duplist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:18:37 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/28 13:33:33 by nel-baz          ###   ########.fr       */
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
	// for (int i = 0; i < size; i++)
	// 	printf("len_tab[%d] = %d,  ", i, len_tab[i]);
	// printf("\n");
	len = max_len(len_tab, size);
	// printf("len of seq = %d\n", len);
	// getchar();
	j = get_index(len_tab, size);
	// printf("index of largest = %d\n", j);
	lis_tab = malloc(sizeof(int) * len);
	if (!lis_tab)
		return (NULL);
	lis_tab[--len] = tab[j];
	j = index_tab[j];
	while (--len >= 0)
	{
		lis_tab[len] = tab[j];
		j = index_tab[j];
	}
	free(len_tab);
	free(index_tab);
	return (lis_tab);
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

// void	get_array(int *array, t_stack *node, int big, int last)
// {
// 	while (big < last)
// 	{
// 		node = node->next;
// 		array[big++] = node->data;
// 	}
// }

// int	get_duplist(t_stack *stack_a, int size)
// {
// 	int		*array;
// 	int		pos;
// 	t_stack	*first_node;
// 	int		end;

// 	array = malloc(sizeof(int) * size);
// 	array[0] = have_min_number(stack_a);
// 	pos = get_position(stack_a);
// 	get_array(array, first_node, 1, size);
// }
