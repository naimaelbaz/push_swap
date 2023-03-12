/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:38:32 by nel-baz           #+#    #+#             */
/*   Updated: 2023/03/01 19:17:05 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack *stack)
{
	int			tmp;
	t_stack		*str;

	str = stack->next;
	if (stack == NULL || str == NULL)
		return ;
	tmp = stack->data;
	stack->data = str->data;
	str->data = tmp;
}

void	swap_ab(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
