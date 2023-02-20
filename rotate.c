/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:19:06 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/20 16:37:18 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*str;

	if ((*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	str = *stack;
	while (str && str->next != NULL)
		str = str->next;
	str->next = *stack;
	(*stack)->prev = str;
	(*stack)->next = NULL;
	*stack = tmp;
	(*stack)->prev = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_a_tmp(t_stack **stack_a)
{
	rotate(stack_a);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
