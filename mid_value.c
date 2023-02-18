/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:40:16 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/18 04:30:45 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	have_max_number(t_stack *stack_a)
{
	int			max;
	t_stack		*stack;

	max = stack_a->data;
	stack = stack_a->next;
	while (stack != NULL)
	{
		if (stack->data > max)
			max = stack->data;
		stack = stack->next;
	}
	return (max);
}

int	have_the_mid(t_stack *stack_a)
{
	int	min;
	int	max;
	int	mid;

	min = have_min_number(stack_a);
	max = have_max_number(stack_a);
	mid = (min + max) / 2;
	return (mid);
}

int	mid_value(t_stack *stack_a)
{
	int	mid;
	int	var;
	int	data;

	mid = have_the_mid(stack_a);
	var = to_pos(stack_a->data - mid);
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (to_pos(stack_a->data - mid) < var)
		{
			var = to_pos(stack_a->data - mid);
			data = stack_a->data;
		}
		stack_a = stack_a->next;
	}
	return (data);
}
