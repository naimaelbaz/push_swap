/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:38:32 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/24 16:45:24 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_sorted(t_stack	*stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	*convert_to_array(t_stack *stack_tmp, int size)
{
	t_stack	*node;
	int		*tab;
	int		i;

	i = 0;
	node = stack_tmp;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (node != NULL && i < size)
	{
		tab[i] = node->data;
		i++;
		node = node->next;
	}
	return (tab);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	*get_tab(int *tab, int *len_tab, int *index_tab, int size)
{
	int	i;
	int	j;

	i = 1;
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
	return (index_tab);
}
