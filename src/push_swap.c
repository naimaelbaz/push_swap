/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:52:58 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/28 13:51:00 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		printf("data---->%d  pos--->%d\n", stack_a->data, stack_a->position);
		stack_a = stack_a->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = check_numberofarg(argc, argv, stack_a);
		if (ft_lstsiz(stack_a) < 6)
		{
			sort_small_num(stack_a, stack_b, ft_lstsiz(stack_a));
		}
		else
		{
			pb(&stack_a, &stack_b, ft_lstsiz(stack_a));
			get_index_args(stack_a, ft_lstsiz(stack_a));
			get_index_args(stack_b, ft_lstsiz(stack_b));
			push_to_a(&stack_a, &stack_b);
		}
	}
	return (0);
}
