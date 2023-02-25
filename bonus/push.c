/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:10:24 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/25 23:11:22 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*tmp;

	if (*stack1 == NULL)
		return ;
	if ((*stack1)->next != NULL)
	{
		tmp = (*stack1)->next;
		if (*stack2 == NULL)
			(*stack1)->next = NULL;
		else
			(*stack1)->next = *stack2;
		*stack2 = *stack1;
		*stack1 = tmp;
		(*stack1)->prev = NULL;
	}
	else
	{
		(*stack1)->next = *stack2;
		*stack2 = *stack1;
		*stack1 = NULL;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_a, stack_b);
}
