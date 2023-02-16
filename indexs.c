/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:44:10 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/14 10:51:44 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pair_size(t_stack *stack, int size_stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_stack / 2)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
	j = size_stack / 2;
	i = 0;
	while (i < size_stack / 2)
	{
		stack->position = -j;
		stack = stack->next;
		i++;
		j--;
	}
}

void	impair_size(t_stack *stack, int size_stack)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size_stack / 2)
	{
		stack->position = i;
		stack = stack->next;
		i++;
	}
	j = i - 1;
	i = 0;
	while (i < size_stack / 2)
	{
		stack->position = -j;
		stack = stack->next;
		i++;
		j--;
	}
}

void	get_index_args(t_stack *stack, int size_stack)
{
	if (size_stack % 2 == 0)
		pair_size(stack, size_stack);
	else
		impair_size(stack, size_stack);
}

