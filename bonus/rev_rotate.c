/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:54:16 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/01 19:28:16 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	node = *stack;
	while (node && node->next->next != NULL)
		node = node->next;
	last_node = node->next;
	node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	rev_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
