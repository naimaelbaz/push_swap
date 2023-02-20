/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 01:30:47 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/19 04:32:31 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_num(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size == 2)
		ft_sort2(stack_a, size);
	else if (size == 3)
		ft_sort3(stack_a, stack_b, size);
	else if (size == 4)
		ft_sort4(stack_a, stack_b, size);
	else if (size == 5)
		ft_sort4(stack_a, stack_b, size);
}

void	ft_sort2(t_stack **stack_a, int size)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		swap_a(stack_a);
}

void	ft_sort3(t_stack *stack_a, t_stack *stack_b, int size)
{
	
}
