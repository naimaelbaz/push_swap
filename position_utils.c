/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:44:54 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/16 05:42:19 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_langest(t_stack *stack, int data)
{
	while (stack != NULL)
	{
		if (stack->data > data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	max_pos_a(t_stack *stack)
{
	int	max;
	int	pos_max;

	max = stack->data;
	while (stack != NULL)
	{
		if (stack->data >= max)
		{
			max = stack->data;
			if (stack->next == NULL)
				pos_max = stack->position + 1;
			else
				pos_max = stack->next->position;
		}
		stack = stack->next;
	}
	return (pos_max);
}
