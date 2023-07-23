/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:32 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/13 19:20:37 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack *stack)
{
	int			tmp;
	t_stack		*str;

	if (stack == NULL || stack->next == NULL)
		return ;
	str = stack->next;
	tmp = stack->data;
	stack->data = str->data;
	str->data = tmp;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || !stack_a->next || !stack_b->next)
		return ;
	swap(stack_a);
	swap(stack_b);
}
