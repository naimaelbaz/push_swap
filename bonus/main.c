/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:26:22 by nel-baz           #+#    #+#             */
/*   Updated: 2023/02/26 17:53:20 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	give_res(t_stack *stack_a, t_stack *stack_b)
{
	if (a_is_sorted(stack_a) && b_is_empty(stack_b))
		ft_putstr_fd("OK\n", 1);
	else if (!a_is_sorted(stack_a) || !b_is_empty(stack_b))
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = check_numberofarg(argc, argv, stack_a);
		check_instr(&stack_a, &stack_b);
		// while (stack_a != NULL)
		// {
		// 	printf("%d\n", stack_a->data);
		// 	stack_a = stack_a->next;
		// }
		give_res(stack_a, stack_b);
	}
	return (0);
}
