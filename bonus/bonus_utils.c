/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:27:04 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/25 23:04:41 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	b_is_empty(t_stack *stack_b)
{
	if (stack_b == NULL)
		return (1);
	else
		return (0);
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

void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}



