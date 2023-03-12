/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:07:09 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/01 17:56:22 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest(t_stack *stack)
{
	int	small;

	small = stack->data;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->data < small)
			small = stack->data;
		stack = stack->next;
	}
	return (small);
}

int	is_small(t_stack *stack_a)
{
	int		smallest;
	t_stack	*t;

	smallest = get_smallest(stack_a);
	t = stack_a;
	while (t)
	{
		if (t->data == smallest)
			return (t->position);
		t = t->next;
	}
	return (0);
}

int	position_of_a(t_stack *stack_a, int data)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	tmp = stack_a;
	first = stack_a;
	last = lst_last(stack_a);
	if (data < first->data && data > last->data)
		return (0);
	while (tmp != NULL && tmp->next)
	{
		if (data > tmp->data && data < tmp->next->data)
			return (tmp->next->position);
		tmp = tmp->next;
	}
	if (is_langest(stack_a, data))
		return (max_pos_a(stack_a));
	return (is_small(stack_a));
}

int	*number_of_moves(t_stack *stack_a, t_stack *stack_b)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tmp = stack_b;
	i = 0;
	tab = malloc(sizeof(int) * ft_lstsiz(stack_b));
	if (!tab)
		return (NULL);
	while (tmp != NULL)
	{
		tab[i] = position_of_a(stack_a, tmp->data);
		tmp = tmp->next;
		i++;
	}
	return (tab);
}
