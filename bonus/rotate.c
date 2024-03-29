/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:19:06 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/01 19:16:37 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*str;

	if (!(*stack) || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	str = *stack;
	while (str && str->next != NULL)
		str = str->next;
	str->next = *stack;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
